/*Aplicación que define una matriz de 2*3 mediante funciones - 27/05/2019 - 10:50 - Angela Díaz*/

#include<stdio.h>
#include<stdlib.h>

//Definición de constantes
#define FILA1 2
#define COL1 3
#define FILA2 3
#define COL2 4

void inicializar_matriz1(int matriz1[FILA1][COL1]);
void capturar_matriz1(int matriz1[FILA1][COL1]);
void presentar_matriz1(int matriz1[FILA1][COL1]);
void inicializar_matriz2(int matriz2[FILA2][COL2]);
void capturar_matriz2(int matriz1[FILA2][COL2]);
void presentar_matriz2(int matriz1[FILA2][COL2]);
void inicializar_matriz_resultante(int matriz_resultante[FILA1][COL2]);
void presentar_matriz_resultante(int matriz_resultante[FILA1][COL2]);
void multiplicar_matrices(int matriz1[FILA1][COL1], int matriz2[FILA2][COL2], int matriz_resultante[FILA1][COL2]);

int main(){
	
	int matriz1[FILA1][COL1];	
	int matriz2[FILA2][COL2];
	int matriz_resultante[FILA1][COL2];
	
	inicializar_matriz1(matriz1);
	inicializar_matriz2(matriz2);
	inicializar_matriz_resultante(matriz_resultante);
	
	capturar_matriz1(matriz1);
	capturar_matriz2(matriz2);
	
	presentar_matriz1(matriz1);
	presentar_matriz2(matriz2);
	multiplicar_matrices(matriz1, matriz2, matriz_resultante);
	presentar_matriz_resultante(matriz_resultante);
	
	return 0;
	
}//Cierre del bloque principal

void inicializar_matriz1(int matriz1[FILA1][COL1]){
	for (int i=0; i<FILA1; i++){
		for (int j=0; j<COL1; j++){
			matriz1[FILA1][COL1]=0; 
		}//Cierre for columnas inicializar matriz1
	}//Cierre for filas inicializar matriz1
}//Cierre función inicializar matriz1

void inicializar_matriz2(int matriz2[FILA2][COL2]){
	for (int i=0; i<FILA2; i++){
		for (int j=0; j<COL2; j++){
			matriz2[FILA2][COL2]=0; 
		}//Cierre for columnas inicializar matriz1
	}//Cierre for filas inicializar matriz1
}//Cierre función inicializar matriz2

void inicializar_matriz_resultante(int matriz_resultante[FILA1][COL2]){
	for (int i=0; i<FILA1; i++){
		for (int j=0; j<COL2; j++){
			matriz_resultante[FILA1][COL2]=0; 
		}//Cierre for columnas inicializar matriz1
	}//Cierre for filas inicializar matriz1
}//Cierre función inicializar matriz2

void capturar_matriz1(int matriz1[FILA1][COL1]){
	printf("Captura de datos para la primera matriz:");
	for (int i=0; i<FILA1; i++){
	printf("\n\tIngreso de datos de la fila %d\n", (i+1));
		for (int j=0; j<COL1; j++){
			printf("\t\tEscriba el valor entero para la columna %d: ", (j+1));
			scanf("%d",&matriz1[i][j]);
		}//Cierre for columnas captura
	}//Cierre for filas captura
}//Cierre función capturar matriz1

void capturar_matriz2(int matriz2[FILA2][COL2]){
	printf("\n\nCaptura de datos para la segunda matriz:");
	for (int i=0; i<FILA2; i++){
	printf("\n\tIngreso de datos de la fila %d\n", (i+1));
		for (int j=0; j<COL2; j++){
			printf("\t\tEscriba el valor entero para la columna %d: ", (j+1));
			scanf("%d",&matriz2[i][j]);
		}//Cierre for columnas captura
	}//Cierre for filas captura
}//Cierre función capturar matriz2

void presentar_matriz1(int matriz1[FILA1][COL1]){
	printf("\nContenido de la primera matriz:\n");
	for (int i=0; i<FILA1; i++){
		for (int j=0; j<COL1; j++){
			printf("%d	",matriz1[i][j]);
		}//Cierre for columnas presentación
		printf("\n");
	}//Cierre for filas presentación
}//Cierre función presentar matriz1

void presentar_matriz2(int matriz2[FILA2][COL2]){
	printf("\nContenido de la segunda matriz:\n");
	for (int i=0; i<FILA2; i++){
		for (int j=0; j<COL2; j++){
			printf("%d	",matriz2[i][j]);
		}//Cierre for columnas presentación
		printf("\n");
	}//Cierre for filas presentación
}//Cierre función presentar matriz2

void multiplicar_matrices(int matriz1[FILA1][COL1], int matriz2[FILA2][COL2], int matriz_resultante[FILA1][COL2]){
	for(int i=0; i<FILA1; i++){
			for(int j=0; j<COL2; j++){
					for(int k=0; k<COL1; k++){
						matriz_resultante[i][j] += matriz1[i][k] * matriz2[k][j];
				}//Cierre for columnas matriz1
			}//Cierre del ciclo for columnas matriz2
		}//Cierre del ciclo for filas matriz resultante
}//Cierre función multiplicar matrices

void presentar_matriz_resultante(int matriz_resultante[FILA1][COL2]){
	printf("\nContenido de la matriz resultante:\n");
	for (int i=0; i<FILA1; i++){
		for (int j=0; j<COL2; j++){
			printf("%d	",matriz_resultante[i][j]);
		}//Cierre for columnas presentación
		printf("\n");
	}//Cierre for filas presentación
}//Cierre función presentar matriz_resultante

