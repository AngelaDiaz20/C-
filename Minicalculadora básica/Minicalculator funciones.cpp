/*Aplicación que captura dos números enteros y realiza las operaciones básicas (suma, resta, multiplicación y división) - D16/09/2018 - 17:45 -Angela Patricia Díaz Martin*/

#include <stdio.h>
#include <stdlib.h>

int sumar (int num1, int num2);
int restar (int num1, int num2);
int multiplicar (int num1, int num2);
int dividir (int num1, int num2);
void presentar_resultado (int num1, int num2, int result);

int main(){
	
	int num1, num2, result, opcion;
	num1 = num2 = result = opcion = 0;

	printf("LA MINICALCULATOR\n");

	printf("Ingrese el primer n\243mero: ");
	scanf("%d",&num1);
	
	printf("Ingrese el segundo n\243mero: ");
	scanf("%d",&num2);
	
	printf("\nMen\243 de operaciones \n1.Suma \n2.Resta \n3.Multiplicaci\242n \n4,Divisi\242n");
	
	printf("\nEsocoja la opci\242n deseada: ");
	scanf("%d",&opcion);
	
	switch(opcion){
		
		case 1:
			result=sumar(num1, num2);
			printf("\nLa suma entre %d y %d es:%d");
			presentar_resultado(num1, num2, result);	
		break;
		
		case 2:
			result=restar(num1, num2);
			printf("\nLa resta entre %d y %d es:%d");
			presentar_resultado(num1, num2, result);
		break;
		
		case 3:
			result=multiplicar(num1, num2);
			printf("\nLa multiplicaci\242n entre %d y %d es:%d");
			presentar_resultado(num1, num2, result);
		break;
		
		case 4:
			result=dividir(num1, num2);
			printf("\nLa divisi\242n entre %d y %d es:%d");
			presentar_resultado(num1, num2, result);
		break;
		
		default:
			printf("\nOpci\242n no considerada.");
		break;
		
	}//Cierre del switch
	
	printf("\n\n");
	
	system ("PAUSE");
	return 0;
	
}//Cierre del bloque principal

int sumar (int num1, int num2){
	return num1+num2;
}//Cierre de la función sumar

int restar (int num1, int num2){
	return num1-num2;
}//Cierre de la función sumar

int multiplicar (int num1, int num2){
	return num1*num2;
}//Cierre de la función sumar

int dividir (int num1, int num2){
	return num1/num2;
}//Cierre de la función sumar

void presentar_resultado(int num1, int num2, int result){
	printf("%d ",num1, num2, result);
  }//Cierre de la función presentar

