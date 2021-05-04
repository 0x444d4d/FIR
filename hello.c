#include <cstdio>
#include <stdio.h>

#define nv 20
#define nc 5

void main()
{ 
    int v_datos [nv];
    int v_coef [nc];

    int i,j;
    printf("primer bucle\n");
    for(i=0;i<nv;i++)
    	v_datos[i]=i;

    for(j=0;j<nc;j++){
    	v_coef[j]=j;
    }



    for ( j = 0; j < nv; j++)
    	printf("%d\n",v_datos[j]);
    for ( j = 0; j < nc; j++)
    	printf("%d\n",v_coef[j]);

}
