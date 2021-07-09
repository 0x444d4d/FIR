#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define nv 3500
#define nc 3

#define F_ERROR 1
#define F_SUCCESS 0

int read_csv(char* name, int n, float **values, int *n_read) {
	int size;
	size = n; // Por ejemplo
	float* restrict v_fich_num_csv = (float*) malloc(size * sizeof(float));
	int i = 0;

	// También puede ser otros tipos
	FILE *fich_num = fopen(name, "r");

	// Si no existe fichero se indica
	if(fich_num == NULL) {
		printf("No se puede abrir fichero\n");
		return F_ERROR;
	}

	char line[1000] ="";
	char *s = ",";
	char* token;

	while(fscanf(fich_num, "%s",line) != EOF && i < size){
		token = strtok(line,s);
		while ((token != NULL) && (i < size)) {
			float value = atof(token);
			v_fich_num_csv[i++] = value;
			//printf("read: %f, %f", value, v_fich_num_csv[i - 1]);
			token = strtok(NULL, s);
		}
	}
	*n_read = i;
	*values = (float*) malloc(n * sizeof(float));
	memcpy(*values, v_fich_num_csv, (sizeof(float) * i));

	free(v_fich_num_csv);
	fclose(fich_num);

	return F_SUCCESS;
}

float apply_coeffs(float* values, float* coeffs, int n) {
	float acc = 0;
	int i;
	for (i = 0; i < n; ++i) {
		acc += values[i] * coeffs[i];
	}
	return acc;
}

//shift to buffer.
int stob(float* buffer, int buffer_size, float* source, int source_size) {
	static float* buff;
	static float* src;
	static int n_shift;
	static int buff_size;
	static int src_size;
	static int initialized;
	//reentrant version
	if (buffer == NULL && source == NULL) {
		if (initialized == 0) {
			return -1;
		}
	}
	//first call - initialize;
	else {
		buff = buffer;
		src = source;
		n_shift = 0;
		buff_size = buffer_size;
		src_size = source_size;
		initialized = 1;
	}

	if (n_shift < src_size + buff_size) {
		int i;
		for (i = 0; i < buff_size - 1; ++i) {
			buff[i] = buff[i + 1];
		}
		if (n_shift < src_size) {
			buff[buff_size - 1] = src[n_shift++];
		} else{
			buff[buff_size - 1] = 0;
			++n_shift;
		}
	} else {
		//reached source end;
		return 0;
	}

	return n_shift;
}

/*
	 void fir2(float *values, int n_values, float* coeff, int n_coeff) {
	 float* buffer = (float *) malloc(sizeof(float) * n_coeff);

	 int i;
	 for (i = 0; i < n_coeff; ++i) {
	 buffer[i] = 0;
	 }

//Mueve al buffer los valores actualizados.
i = stob(buffer, n_coeff, values, n_values);
while (i) {
printf("%f\n", apply_coeffs(buffer, coeff, n_coeff));
i = stob(NULL, 0, NULL, 0);
}


}
*/

/*
	 float* fir(float *values, int n_values, float* coeff, int n_coeff, int* r_size) {
	 float * sample;
	 int buffer_size = (n_values + (2 *n_coeff));
 *r_size = n_values + n_coeff + 1;
//Creamos un buffer con los valores y el inicio y fin, del tamaño igual a n_coef, vacios.
float buffer[nv + (2*nc)]; // = (float*) malloc(sizeof(float) * buffer_size);
memcpy(buffer + n_coeff, values, (n_values * sizeof(float)));
int i;
for (i = 0; i < n_coeff; ++i) {
buffer[i] = 0;
buffer[buffer_size-1 - i] = 0;
}

float* output_base = (float*) malloc(sizeof(float) * (*r_size));
float* output = output_base;
sample = buffer;
float value;
for (i = 0; i < (*r_size); ++i) {
value = apply_coeffs(sample, coeff, n_coeff);
++sample;
 *(output++) = value;
//fflush(stdout);
//printf("%f,", value);
}

free(buffer);
return output_base;
}
*/

void prologe(float* val, int nval, float* coef, int ncoef) {
	int i, j;
	float acc = 0;
	for (i = 0; i < ncoef; ++i) {
		for(j = 0; (j <= i) && ((i - j) < nval); ++j) {
			//printf("coef: %f, val: %f ", coef[ncoef - 1 - j], val[i - j]);
			acc += coef[ncoef - 1 - j] * val[i - j];
		}
		printf("%f\n", acc);
		acc = 0;
	}
}

void epiloge(float* val, int nval, float* coef, int ncoef) {
	int i, j;
	float acc = 0;
	float* ep = val + (nval - ncoef - 1); //Seccion a la que se le aplica el epilogo.
	for (i = 0; i < ncoef; ++i) {
		for (j = 0; (j + i) < ncoef; ++j) {
			//printf("coef: %f, val: %f ", coef[j], ep[j + i]);
			acc += coef[j] * ep[j + i];
		}
		//printf("%f\n", acc);
		acc = 0;
	}
}

void body (float* val, int nval, float* coef, int ncoef) {

	int i = 0;
	int j = 0;
	float *base = val + ncoef;
	while (i++ < (nval - ncoef)) {
		float acc0 = 0;
		float acc1 = 0;
		float acc2 = 0;
		float acc3 = 0;
		float acc4 = 0;

		int remaining = ((nval - 2*ncoef) - i);

		if (remaining >= 5) {
			for (j = 0; j < ncoef; ++j) {
				acc0 += (base + 0)[j] * coef[j];
				acc1 += (base + 1)[j] * coef[j];
				acc2 += (base + 2)[j] * coef[j];
				acc3 += (base + 3)[j] * coef[j];
				acc4 += (base + 4)[j] * coef[j];
			}
			base += 5;
		} else if (remaining > 0) {
			for (j = 0; j < remaining; ++j) {
				int k = 0;
				acc0 = 0;
				for (k = 0; k < ncoef; ++k) {
					acc0 += (base + j)[k]  * coef[k];
				}
			}

		}
		//printf("%f\n", apply_coeffs(val + 0, coef, ncoef ));
		//printf("%f\n", apply_coeffs(val + 1, coef, ncoef ));
		//printf("%f\n", apply_coeffs(val + 2, coef, ncoef ));
		//printf("%f\n", apply_coeffs(val + 3, coef, ncoef ));
		//printf("%f\n", apply_coeffs(val + 4, coef, ncoef ));
	}
}

void body2 (float* val, int nval, float* coef, int ncoef) {
	int i = 0;
	int k = (nval - ncoef)/2;
	int j = 0;
	float *base = val + ncoef;
	while (k++ < (nval - ncoef)) {
		float acc0 = 0;
		float acc1 = 0;
		float acc2 = 0;
		float acc3 = 0;
		float acc4 = 0;

		int remaining = ((nval - 2*ncoef) - i);

		if (remaining >= 5) {
			for (j = 0; j < ncoef; ++j) {
				acc0 += (base + 0)[j] * coef[j];
				acc1 += (base + 1)[j] * coef[j];
				acc2 += (base + 2)[j] * coef[j];
				acc3 += (base + 3)[j] * coef[j];
				acc4 += (base + 4)[j] * coef[j];
			}
			base += 5;
		} else if (remaining > 0) {
			for (j = 0; j < remaining; ++j) {
				int k = 0;
				acc0 = 0;
				for (k = 0; k < ncoef; ++k) {
					acc0 += (base + j)[k]  * coef[k];
				}
			}

	while (i++ < (nval - ncoef)/2) {
		float acc0 = 0;
		float acc1 = 0;
		float acc2 = 0;
		float acc3 = 0;
		float acc4 = 0;

		int remaining = ((nval - 2*ncoef) - i);

		if (remaining >= 5) {
			for (j = 0; j < ncoef; ++j) {
				acc0 += (base + 0)[j] * coef[j];
				acc1 += (base + 1)[j] * coef[j];
				acc2 += (base + 2)[j] * coef[j];
				acc3 += (base + 3)[j] * coef[j];
				acc4 += (base + 4)[j] * coef[j];
			}
			base += 5;
		} else if (remaining > 0) {
			for (j = 0; j < remaining; ++j) {
				int k = 0;
				acc0 = 0;
				for (k = 0; k < ncoef; ++k) {
					acc0 += (base + j)[k]  * coef[k];
				}
			}

		}
		//printf("%f\n", apply_coeffs(val + 0, coef, ncoef ));
		//printf("%f\n", apply_coeffs(val + 1, coef, ncoef ));
		//printf("%f\n", apply_coeffs(val + 2, coef, ncoef ));
		//printf("%f\n", apply_coeffs(val + 3, coef, ncoef ));
		//printf("%f\n", apply_coeffs(val + 4, coef, ncoef ));
	}
}

int main()
{ 
	float* v_datos = NULL;
	float* v_datos_base = NULL;
	float* v_coef = NULL;
	int nc_read;
	int nv_read;

	//Lecutra de los valores y coeficientes.
	int error = read_csv("Coeficientes.csv", nc, &v_coef, &nc_read);
	if (error == F_ERROR) {
		printf("Error al leer los coeficientes\n");
	}

	error = read_csv("musica4.csv", nv, &v_datos, &nv_read);
	if (error == F_ERROR) {
		printf("Error al leer los valores\n");
	}

	v_datos_base = v_datos;
	printf("datos: %d coeficientes: %d\n", nv_read, nc_read);
	{ // Primera implementacion
		prologe(v_datos_base, nv_read, v_coef, nc_read);
		v_datos += nc_read;

		int i = 0;
		int j;
		while (i++ < (nv_read - nc_read * 2)/5) {
			float acc0 = 0;
			float acc1 = 0;
			float acc2 = 0;
			float acc3 = 0;
			float acc4 = 0;

			int remaining = ((nv_read - 2*nc_read) - i);

			if (remaining >= 5) {
				for (j = 0; j < nc_read; ++j) {
					acc0 += (v_datos + 0)[j] * v_coef[j];
					acc1 += (v_datos + 1)[j] * v_coef[j];
					acc2 += (v_datos + 2)[j] * v_coef[j];
					acc3 += (v_datos + 3)[j] * v_coef[j];
					acc4 += (v_datos + 4)[j] * v_coef[j];
				}
				//printf("%f\n", acc0);
				//printf("%f\n", acc1);
				//printf("%f\n", acc2);
				//printf("%f\n", acc3);
				//printf("%f\n", acc4);
			} else if (remaining > 0) {
				for (j = 0; j < remaining; ++j) {
					int k = 0;
					acc0 = 0;
					for (k = 0; k < nc_read; ++k) {
						acc0 += (v_datos + j)[k]  * v_coef[k];
					}
				}
			}

			v_datos += 5;
		}
		epiloge(v_datos_base, nv_read, v_coef, nc_read);
	}

	{//2 bucle en una funcion.
		prologe(v_datos_base, nv_read, v_coef, nc_read);
		body(v_datos_base, nv_read, v_coef, nc_read);
		epiloge(v_datos_base, nv_read, v_coef, nc_read);
	}
	//3
		prologe(v_datos_base, nv_read, v_coef, nc_read);
		body2(v_datos_base, nv_read, v_coef, nc_read);
		epiloge(v_datos_base, nv_read, v_coef, nc_read);
	//4
	//5
	//6


	//int r_size;
	//float* result;
	//result = fir(v_datos, nv_read, v_coef, nc_read, &r_size );
	//fir2(v_datos, nv_read, v_coef, nc_read);

	//int i;
	//for (i = 0; i < r_size; ++i) {
	//	printf("%d: %f\n", i, result[i]);
	//}


	//int size;
	//fir(v_datos, nv_read, v_coef, nc_read, &size);
	//float* result = fir(v_datos, nv_read, v_coef, nc_read, &size);
	//for (i = 0; i < size; ++i) {
	//printf("%f ", result[i]);
	//}
	free(v_coef);
	free(v_datos_base);

	printf("FIN\n");

	//	while(1);
}


//dudas - memoria / desenrrollado / solo imprimir? / 50 coeff -> 21 coeff
