/*Aplicación que captura 2 vectores de 5 posiciones, los suma y muestra el contenido de ellos y el vector resultante -20/05/2019 - 12:51 - Angela Díaz */

#include<stdio.h>
#include <stdlib.h>

int main (){
	
	int vector1[5];
	int vector2[5];
	int vector_resultado[5];	
	
	for (int i=0; i<5; i++){
		vector1[i] = vector2[i] = vector_resultado[i] =0;
	}//Cierre del for de inicialización de vectores
	
	printf("Datos primer vector:\n");
	for (int i=0; i<5; i++){
		printf("Ingrese un numero entero para la posicion %d: ", i+1);
		scanf("%d",&vector1[i]);
	}//Cierre del for de captura del vector1
	
	printf("\nDatos segundo vector:\n");
	for (int i=0; i<5; i++){
		printf("Ingrese un numero entero para la posicion %d: ", i+1);
		scanf("%d",&vector2[i]);
	}//Cierre del for de captura del vector2
	
	for(int i=0; i<5; i++){
		vector_resultado[i]=vector1[i]+vector2[i];
	}//Cierre del for de suma de vectores
	
	printf("\n\nContenido del primer vector:\n");
	for(int i=0; i<5; i++){
		printf("%d ",vector1[i]);
	}//Cierre del for de presentación del vector1
	
	printf("\n\nContenido del segundo vector:\n");
	for(int i=0; i<5; i++){
		printf("%d ",vector2[i]);
	}//Cierre del for de presentación del vector2
	
	printf("\n\nContenido del vector resultante:\n");
	for(int i=0; i<5; i++){
		printf("%d ",vector_resultado[i]);
	}//Cierre del for de presentación del vector_resultado
	return 0; 
	
}//Cierre del bloque principal
