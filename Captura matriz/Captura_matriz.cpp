/*Aplicaci�n que captura y presenta una matriz de 2*3 - 27/05/2019 - 10:50 - Angela D�az*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int matriz[2][3];
	
	for (int i=0; i<2; i++){
		for (int j=0; j<3; j++){
			matriz[i][j]=0;
		}//Cierre for columnas inicializaci�n
	}//Cierre for filas inicializaci�n
	
	for (int i=0; i<2; i++){
		printf("\nIngreso de datos de la fila %d\n", (i+1));
		for (int j=0; j<3; j++){
			printf("Escriba el valor entero para la columna %d: ", (j+1));
			scanf("%d",&matriz[i][j]);
		}//Cierre for columnas captura
	}//Cierre for filas captura
	
	printf("\nContenido de la matriz:\n");
	for (int i=0; i<2; i++){
		for (int j=0; j<3; j++){
			printf("%d ",matriz[i][j]);
		}//Cierre for columnas presentaci�n
		printf("\n");
	}//Cierre for filas presentaci�n
	
	return 0;
	
}//Cierre del bloque principal
