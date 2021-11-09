/*Captura y presentaci�n de una lista de nodos L01/07/2019 - 16:32 - Angela D�az*/

#include <stdio.h>
#include <stdlib.h>

//Definici�n del nodo (estructura autoreferenciada) nodoLista
struct nodoLista{
	char dato; //varialbe para almacenar un caracter digitado por el usuario
	struct nodoLista *ptrSiguiente; //Apuntador al siguiente nodo
};

//Definici�n de un alias para la estructura de nodo nodoLista
typedef struct nodoLista NodoLista;

//Definici�n de un alias para un apuntador al nodo nodoLista
typedef NodoLista *ptrNodoLista;

//Prototipado de funciones por referencia
void insertar(ptrNodoLista *ptrS, char valor);
void imprimeLista(ptrNodoLista ptrActual);
int estaVacia(ptrNodoLista ptrS);
char eliminar(ptrNodoLista *ptrS, char valor);

int main(){
	
	//Declaraci�n de un apuntador tipo apuntador al nodo inicial de la lista
	ptrNodoLista ptrInicial;	
	ptrInicial = NULL;

	//Variable de opci�n de men�
	int eleccion = 0;
	
	//Variable que almacena el dato ingresado por el usuario
	char elemento = ' ';

	//Ciclo de evaluaci�n de la opci�n escogida por el usuario
	while(eleccion != 5){

		//Invocaci�n del men�
		printf("\nMENU DE UNA LISTA DE DATOS\n");
		printf("\n1. Insertar un dato en la lista");
		printf("\n2. Presentar el contenido de la lista");
		printf("\n3. Borrar el PRIMER nodo o dato de la lista");
		printf("\n4. Borrar el ULTIMO nodo o dato de la lista");
		printf("\n5. Salir de la aplicacion\n");
		printf("\nEscoja una opcion (1/3): ");
		scanf("%d", &eleccion);

		//Evaluar la opci�n
		switch(eleccion){
	
			//Opci�n 1 del men� (insertar nodo en la lista)
			case 1:
				printf("Introduzca un caracter: ");
				scanf("%s", &elemento);
				insertar(&ptrInicial, elemento);
			break;
	
		//Opci�n 2 del men� (presentar nodo de la lista)
	
			case 2:
				//Evaluar si la lista no est� vac�a entonces pedir dato a eliminar
				if(!estaVacia(ptrInicial)){
					//Presentaci�n del contenido de la lista
					imprimeLista(ptrInicial);
				}//Cierre del if lista no vac�a
				else{
					printf("\nLA LISTA ESTA VACIA...\n\n");
				}//Cierre del else lista no vac�a
			break;
		
			//Opci�n 3 del men� (eliminar EL PRIMER nodo de la lista) - COLA
			case 3:
				//Evaluar si la lista no est� vac�a entonces pedir dato a eliminar
				if(!estaVacia(ptrInicial)){
					printf("Introduzca el dato a eliminar: ");
					scanf("%s", &elemento);
					//Evaluar si el dato existe en la lista entonces eliminarlo
					if(eliminar(&ptrInicial, elemento)){
						printf("\n\ndato %c eliminado.\n\n", elemento);
						//Presentaci�n del contenido de la lista
						imprimeLista(ptrInicial);
					}//Cierre del if eliminar dato
					else{
						printf("\n\nel dato %c NO es el primero de la pila\n\n",elemento);
					}//Cierre del else eliminar dato
		
				}//Cierre del if lista no vac�a
				
				else{	
					printf("\nLA LISTA ESTA VACIA...\n\n");
				}//Cierre del else lista no vac�a
			break;
			
			case 5:	
				printf("\n\nFIN DE LA APLICACION...\n\n");
			break;
		
			default:
				printf("\nOpcion no considerada. Escoja una opcion entre 1 y 5...\n");
			break;
			
		} //Cierre del switch evaluar opci�n escogida

	} //Cierre del ciclo de evaluaci�n de opci�n escogida

	printf("\n\n");
	system("PAUSE");
	return 0;
} //Cierre funci�n principal

//Declaraci�n y desarrollo de la funci�n de inserci�n de un nuevo dato en la lista
void insertar(ptrNodoLista *ptrS, char valor){
	//Declaraci�n de un apuntador a un nuevo nodo
	ptrNodoLista ptrNuevo;
	//Declaraci�n de un apuntador a un nodo previo de la lista
	ptrNodoLista ptrAnterior;
	//Declaraci�n de un apuntador al nodo actual de la lista
	ptrNodoLista ptrActual;

	//Asignar memoria din�micamente para crear un nuevo nodo
	ptrNuevo = (NodoLista *)malloc(sizeof(NodoLista));

	//Asignar el caracter digitado al miembro dato del nodo nuevo
	ptrNuevo->dato = valor;
	//Asignar NULL al apuntador del nodo (No enlazarlo aun a la lista)
	ptrNuevo->ptrSiguiente = NULL;
	
	//Asignar NULL al apuntador que apunta al nodo previo de la lista
	ptrAnterior = NULL;
	//Asignar al apuntador actual el nodo inicial de la lista (cabecera)
	ptrActual = *ptrS;
	
	//Ciclo que identifica en qu� lugar de la lista ha de insertarse el nuevo nodo
	//while(ptrActual != NULL && valor > ptrActual->dato){
	while(ptrActual != NULL){
		ptrAnterior = ptrActual;
		ptrActual = ptrActual->ptrSiguiente;
	}//Cierre dle ciclo de identificaci�n del lugar de inserci�n del nuevo nodo

	//Evaluar si el nuevo nodo se inserta al principio de la lista
	if(ptrAnterior == NULL){	
		//Asignar al apuntador de la cabecera el nuevo nodo
		ptrNuevo->ptrSiguiente = *ptrS;
		*ptrS = ptrNuevo;
	}//Cierre del if de inserci�n al principio de la lista
	//De lo contrario, insertar en nuevo nodo entre el nodo anterior y el actual de la lista
	
	else{
		//Asignar el nuevo nodo al miembro apuntador del nodo anterior
		ptrAnterior->ptrSiguiente = ptrNuevo;
		ptrNuevo->ptrSiguiente = ptrActual;
	}//Cierre del else insertar nuevo nodo entre el anterior y el actual
	
} //Cierre de la funci�n insertar

//Declaraci�n y desarrollo de la funci�n de presentaci�n de la lista
void imprimeLista(ptrNodoLista ptrActual){
	printf("\nLA LISTA ES:\n\n");
	//Ciclo que recorre la lista desde el nodo cabecera hasta el �ltimo nodo
	while(ptrActual != NULL){
		printf("%c -> ", ptrActual->dato);
		ptrActual = ptrActual->ptrSiguiente;
	}

	printf("NULL\n\n");

} //Cierre de la funci�n imprimeLista

//Declaraci�n y desarrollo de la funci�n de evaluaci�n de lista vac�a
int estaVacia(ptrNodoLista ptrS){
	//El apuntador actual es nulo
	return ptrS == NULL;
} //Cierre de la funci�n estaVacia

//Declaraci�n y desarrollo de la funci�n de eliminaci�n de un dato en la pila
char eliminar(ptrNodoLista *ptrS, char valor){
	//Declaraci�n de un apuntador a un nodo previo de la pila
	ptrNodoLista ptrAnterior;
	//Declaraci�n de un apuntador al nodo actual de la pila
	ptrNodoLista ptrActual;
	//Declaraci�n de un apuntador a un nodo temporal
	ptrNodoLista tempPtr;

	//Evaluar si el dato est� en el primer nodo de la pila
	if(valor == (*ptrS)->dato){
		//Asignar el primer nodo de la lista al nodo temporal
		tempPtr = *ptrS;
		//Asignar a la cabecera de la lista el apuntador al siguiente nodo de la lista
		*ptrS = (*ptrS)->ptrSiguiente;
		//Liberar la memoria que ocupa el nodo temporal
		free(tempPtr);
		//Retornar el dato a la instrucci�n donde se invoc� la funci�n eliminar
		return valor;
	}//Cierre del if evaluar dato al principio de la pila
	return '\0';
} //Cierre de la funci�n eliminar
