/*Aplicación que captura una triada de números enteros y los ordena descendentemente - M07/05/2019 - 09:46 - Angela Díaz*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int num1, num2, num3, mayor, medio, menor;
    num1 = num2 = num3 = mayor = medio = menor = 0;
    
    printf("ORDENAMIENTO DESCENDENTE DE UNA TRIADA DE NUMEROS ENTEROS\n");
    
    printf("\nIngrese un primer numero: ");
    scanf("%d", &num1);
    
    printf("Ingrese un segundo numero: ");
    scanf("%d", &num2);   
    
    printf("Ingrese un tercer numero: ");
    scanf("%d", &num3); 
    
    if(num1==num2){
		if(num2==num3);
		printf("\nLos datos ingresados deben ser diferentes.\n\n");
	}//Cierre if evaluación de números iguales
	else if(num1==num3){
		if(num3==num2);
		printf("\nLos datos ingresados deben ser diferentes.\n\n");
	}//Cierre else if evaluación de números iguales
	else if(num2==num3){
		(num3==num1);
		printf("\nLos datos ingresados deben ser diferentes.\n\n");
 	}//Cierre else if evaluación de números iguales

    
    else{
    	if(num1 > num2){
        	if(num1 > num3){
            	mayor = num1;
            	if(num2 > num3){ 
                	medio = num2;
                	menor = num3;
            	}//Cierre if caso 1 (9, 5, 1)
            	else{ 
                	medio = num3;
                	menor = num2;
            	}//Cierre else caso 2 (9, 1, 5)
        	}//Cierre if num1 > num3
        	else{ 
            	mayor = num3;
            	medio = num1;
            	menor = num2;     
        	}//Cierre else caso 4 (5, 1, 9)        
   		}//Cierre if num1 > num2
    	else if(num2 > num3){
        	mayor = num2;
        	if(num1 > num3){ 
            	medio = num1;
            	menor = num3;
        	}//Cierre if caso 3 (5, 9, 1)
        	else{
            	medio = num3;
            	menor = num1;
        	}//Cierre else caso 5 (1, 9, 5)
    	}//Cierre else if num2 > num3
    	else{ 
        	mayor = num3;
        	medio = num2;
        	menor = num1;
    	}//Cierre else caso 6 (1, 5, 9)
    
    	printf("\nLos datos ordenados descendentemente son: %d , %d , %d \n", mayor, medio, menor);
    	printf("\n\n");
    
	}//Cierre else "números diferentes"
	
    system("PAUSE");
    
    return 0;
    
}//Cierre del bloque principal
