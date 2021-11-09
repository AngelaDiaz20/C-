/*Aplicación que ordena descendentemente una triada de números reales y los ordena de manera descendente - J13/09/2018 - 20:20 - Angela Patricia Díaz Martin*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int num1, num2, num3, mayor, medio, menor;

	num1 = num2 = num3 = mayor = medio = menor = 0;

	printf("APLICACION QUE ORDENA 3 NUMEROS DESCENDENTEMENTE\n");

	printf("\nIngrese un primer n\243mero: ");
	scanf("%d", &num1);

	printf("Ingrese un segundo n\243mero: ");
	scanf("%d", &num2);

	printf("Ingrese un tercer n\243mero: ");
	scanf("%d", &num3);
 
	if(num1==num2 || num1==num3 || num2==num3 || num1==num2 && num2==num3) {
		printf("\nNo se puede completar la acci\242n, los n\243meros a ingresar deben ser diferentes.\n\n");
	}


	else {

		if(num1<num2 && num1<num3){
			if(num2<num3){
			mayor=num3; medio=num2; menor=num1; //caso 1 (1, 2, 3)
			}//Cierre if num2<num3
		else{
			mayor=num2; medio=num3; menor=num1; //caso 2 (1, 3, 2)
			}	//Cierre else num2>num3
		}//Cierre if num1<num2 && num1<num3
		
		if(num2<num1 && num2<num3){
			if(num1<num3){
			mayor=num3; medio=num1; menor=num2; //caso 3 (2, 1, 3)
			}//Cierre if num1<num3
		else{
			mayor=num1; medio=num3; menor=num2; //caso 5 (3, 1, 2)
			}//Cierre else num1>num3
		}//Cierre if num2=num1 && num2<num3
		
		if(num3<num1 && num3<num2){
			if(num1<num2){
			mayor=num2; medio=num1; menor=num3; //caso 4 (2, 3, 1)
			}//Cierre if num1<num2
		else{
			mayor=num1; medio=num2; menor=num3; //caso 6 (3, 2, 1)
			}//Cierre else num1>num2
		}//Cierre if num3<num1 && num3<num2
		
		printf("\nLos n\243meros ordenados descendentemente son: %d, %d y %d\n", mayor, medio, menor);
		printf("\n\n");

	}//Cierre del else

	system("PAUSE");

	return 0;

} //Cierre del main
