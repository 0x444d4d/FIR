#include <cstdio>
#include <string.h>
#include <stdlib.h>


#define nv 3500
#define nc 21

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
	const char s[1] = ",";
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
	*values = (float*) malloc(i * sizeof(float));
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

void fir2(float *values, int n_values, float* coeff, int n_coeff) {
	float* buffer = (float *) malloc(sizeof(float) * n_coeff);

	int i;
	for (i = 0; i < n_coeff; ++i) {
		buffer[i] = 0;
	}


	stob(buffer, n_coeff, values, n_values);
	printf("%f\n", apply_coeffs(buffer, coeff, n_coeff));
	while (i = stob(NULL, 0, NULL, 0)) {
		printf("%f\n", apply_coeffs(buffer, coeff, n_coeff));
	}


}

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

void main()
{ 
	float* v_datos = NULL;
	float* v_coef = NULL;
	int nc_read;
	int nv_read;

	int error = read_csv("Coeficientes.csv", nc, &v_coef, &nc_read);
	if (error == F_ERROR) {
	}

	error = read_csv("musica4.csv", nv, &v_datos, &nv_read);
	if (error == F_ERROR) {
	}

	//int r_size;
	//float* result;
	//result = fir(v_datos, nv_read, v_coef, nc_read, &r_size );
	fir2(v_datos, nv_read, v_coef, nc_read);

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
	free(v_datos);

	printf("FIN\n");

	while(1);
}


//dudas - memoria / desenrrollado / solo imprimir? / 50 coeff -> 21 coeff
