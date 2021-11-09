/*Apliación que captura la base y la altura y calcula el área y el perimetro de 3 figuras geométricas planas mediante funciones a petición del usuario - M19/09/2018 - 14:00 - Angela Díaz*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float area (float base, float altura, int opcion);
float perimetro (float base, float altura, int opcion);
float capturar (int dato_ordinal);
void presentar (float altura, float base, float result_area, float result_perimetro, int opcion);

int main (){
	
	float base, altura, result_perimetro, result_area;
	base = altura = result_area = result_perimetro = 0.0;
	int opcion;
	opcion = 0;
	
	printf("FIGURAS GEOMETRICAS PLANAS\n\n");
		
	base=capturar(1);
	altura=capturar(2);
	
	printf("\nMen\243 de figuras \n1.Cuadrado \n2.Rect\240ngulo \n3.Tri\240ngulo rect\240ngulo");
	printf("\n\nEscoja la opci\242n: ");
	scanf("%d",&opcion);
	
	switch(opcion){
		
		case 1:
			result_area=area(base, altura, opcion);
			result_perimetro=perimetro(base, altura, opcion);
			presentar(altura, base, result_area, result_perimetro, opcion);	
		break;
		
		case 2:
			result_area=area(base, altura, opcion);
			result_perimetro=perimetro(base, altura, opcion);
			presentar(altura, base, result_area, result_perimetro, opcion);	
		break;
		
		case 3:
			result_area=area(base, altura, opcion);
			result_perimetro=perimetro(base, altura, opcion);
			presentar(altura, base, result_area, result_perimetro, opcion);	
		break;
		
		default:
			presentar(altura, base, result_area, result_perimetro, opcion);	
		break;
			
	}//Cierre del switch
	
	printf("\n");
	
	system ("PAUSE");
	return 0;
	
}//Cierre del main

float capturar (int dato_ordinal){
	float dato_numerico; dato_numerico = 0.0;
	if(dato_ordinal==1){
		printf("Ingrese la base: ");
		scanf("%f",&dato_numerico);
	}//Cierre del if dato_ordinal==1
	else if(dato_ordinal==2){
		printf("Ingrese la altura: ");
		scanf("%f",&dato_numerico);
	}//Cierre del else if dato_ordinal==2
	return dato_numerico;
}//Cierre de función capturar

float area (float base, float altura, int opcion){
	switch (opcion){
		case 1:
			if(base==altura){
				return base*altura;
			}//Cierre del if cuadrado
		break;
		case 2:
			if(base!=altura){
				return base*altura;
		}//Cierre del if rectángulo 
		break;
		case 3:
			return (base*altura)/2;
		break;
	}//Cierre del switch área
}//Cierre de la función área 

float perimetro (float base, float altura, int opcion){
	switch (opcion){
		case 1:
			if(base==altura){
				return (base*2)+(altura*2);
			}//Cierre del if cuadrado
		break;
		case 2:
			if(base!=altura){
				return (base*2)+(altura*2);
		}//Cierre del if rectángulo
		break;
		case 3:
			return base+altura+(sqrt(pow(base,2))+(pow(altura,2)));
		break;
	}//Cierre del switch perímetro
}//Cierre de la función perimetro

void presentar (float altura, float base, float result_area, float result_perimetro, int opcion){
	switch(opcion){
		
		case 1:
			if(base==altura){
				printf("\nEl \240rea del cuadrado es:%.2f \nEl per\241metro del cuadrado es:%.2f\n", result_area, result_perimetro);
			}//Cierre del if cuadrado
			else{
				printf("\nAcci\242n no completada, la base y altura son diferentes.\n");
			}//Cierre del else cuadrado
		break;
		
		case 2:
			if(base!=altura){
				printf("\nEl \240rea del rect\240ngulo es:%.2f \nEl per\241metro del rect\240ngulo es:%.2f\n", result_area, result_perimetro);
			}//Cierre del if rectángulo
			else{
				printf("\nAcci\242n no completada, la base y altura son iguales.\n");
			}//Cierre del else rectángulo
		break;
			
		case 3:
			printf("\nEl \240rea del tri\240ngulo rect\240ngulo es:%.2f \nEl per\241metro del tri\240ngulo rect\240ngulo es:%.2f\n", result_area, result_perimetro);
		break;
		
		default:
			printf("\nOpci\242n no considerada.\n");
		break; 
		
	}//Cierre del switch
}//Cierre de la funcion presentar
