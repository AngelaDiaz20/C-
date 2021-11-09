/*Aplicación que captura las longitudes de los lados de un triángulo y determina el tipo del mismo, medainte funciones - M14/05/2019 - 16:39 - Angela Díaz*/

#include<stdio.h>
#include<stdlib.h>

void presentar (int lado1, int lado2, int lado3);
int capturar (int orden_num);

int main(){
	
	int lado1, lado2, lado3;
	lado1=lado2=lado3=0;
		
		printf("DETERMINACION TIPO DE TRIANGULO\n");
		
		lado1=capturar(1);
		lado2=capturar(2);
		lado3=capturar(3);
		
		if(lado1==lado2){
			if(lado1==lado3){
				presentar (lado1,lado2,lado3);
			}//Cierre if caso 1 
			else{
				presentar (lado1,lado2,lado3);
			}//Cierre else caso 2
		}//Cierre de if lado1=lado2
		else if (lado2==lado3){
			presentar (lado1,lado2,lado3);
		}//Cierre else if caso 4
		else if(lado1==lado3){
			presentar (lado1,lado2,lado3);
		}//Cierre else if caso 3
		else{	
			presentar (lado1,lado2,lado3);
		}//Cierre else caso 5
	
	return 0;
}//Cierre del bloque principal

int capturar (int orden_num){
	int num_capturado = 0;
	
	if(orden_num==1){
	printf("\nEscriba el valor entero para el primer lado: ");
	scanf("%d",&num_capturado);
	}//Cierre if primer dato
	else if(orden_num==2){
	printf("Escriba el valor entero para el segundo lado: ");
	scanf("%d",&num_capturado);
	}//Cierre else if segundo dato
	else if(orden_num==3){
	printf("Escriba el valor entero para el tercer lado: ");
	scanf("%d",&num_capturado);
	}//Cierre else if tercer dato
	return num_capturado;
}//Cierre de la función capturar


void presentar (int lado1, int lado2, int lado3){
		if(lado1==lado2){
			if(lado1==lado3){
				printf("\nEl triangulo de lados %d, %d y %d es equilatero",lado1,lado2,lado3);
			}//Cierre if caso 1 
			else{
				printf("\nEl triangulo de lados %d, %d y %d es isosceles",lado1,lado2,lado3);
			}//Cierre else caso 2
		}//Cierre de if lado1=lado2
		else if (lado2==lado3){
			printf("\nEl triangulo de lados %d, %d y %d es isosceles",lado1,lado2,lado3);
		}//Cierre else if caso 4
		else if(lado1==lado3){
			printf("\nEl triangulo de lados %d, %d y %d es isosceles",lado1,lado2,lado3);
		}//Cierre else if caso 3
		else{	
			printf("\nEl triangulo de lados %d, %d y %d es escaleno",lado1,lado2,lado3);
		}//Cierre else caso 5
}//Cierre de la función presentar
	

