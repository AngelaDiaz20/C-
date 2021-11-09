/*Captura, eliminaci�n y presentaci�n de una lista de nodos mediante funciones - J11/07/2019 - 16:32 - Angela D�az*/

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
void insertar_orden_ascendente(ptrNodoLista *ptrS, char valor);
void imprimeLista(ptrNodoLista ptrActual);
int estaVacia(ptrNodoLista ptrS);
char eliminar_cola(ptrNodoLista *ptrS, char valor);
char eliminar_pila(ptrNodoLista *ptrS, char valor);

int main(){
	
	//Declaraci�n de un apuntador tipo apuntador al nodo inicial de la lista
	ptrNodoLista ptrInicial;	
	ptrInicial = NULL;

	//Variable de opci�n de men�
	int eleccion = 0;
	
	//Variable que almacena el dato ingresado por el usuario
	char elemento = ' ';

	//Ciclo de evaluaci�n de la opci�n escogida por el usuario
	while(eleccion != 6){

		//Invocaci�n del men�
		printf("\nMENU DE UNA LISTA DE DATOS\n");
		printf("\n1. Insertar un dato en la lista");
		printf("\n2. Insertar un dato en la lista de manera ordenanada (ascendente)");
		printf("\n3. Presentar el contenido de la lista");
		printf("\n4. Borrar el PRIMER nodo o dato de la lista (COLA)");
		printf("\n5. Borrar el ULTIMO nodo o dato de la lista (PILA)");
		printf("\n6. Salir de la aplicacion\n");
		printf("\nEscoja una opcion (1/6): ");
		scanf("%d", &eleccion);

		//Evaluar la opci�n
		switch(eleccion){
	
			//Opci�n 1 del men� (insertar nodo en la lista)
			case 1:
				printf("Introduzca un caracter: ");
				scanf("%s", &elemento);
				insertar(&ptrInicial, elemento);
			break;
			
			//Opci�n 2 del men� (insertar nodo en la lista de modo ascendente)
			case 2:
				printf("Introduzca un caracter: ");
				scanf("%s", &elemento);
				insertar_orden_ascendente(&ptrInicial, elemento);
			break;
			
			//Opci�n 3 del men� (presentar nodo de la lista)
			case 3:
				//Evaluar si la lista no est� vac�a 
				if(!estaVacia(ptrInicial)){
					//Presentaci�n del contenido de la lista
					imprimeLista(ptrInicial);
				}//Cierre del if lista no vac�a
				else{
					printf("\nLA LISTA ESTA VACIA...\n\n");
				}//Cierre del else lista no vac�a
			break;
		
			//Opci�n 4 del men� (eliminar EL PRIMER nodo de la lista) - COLA
			case 4:
				//Evaluar si la lista no est� vac�a entonces pedir dato a eliminar
				if(!estaVacia(ptrInicial)){
					printf("Introduzca el dato a eliminar: ");
					scanf("%s", &elemento);
					//Evaluar si el dato existe en la lista entonces eliminarlo
					if(eliminar_cola(&ptrInicial, elemento)){
						printf("\n\ndato %c eliminado.\n\n", elemento);
						//Presentaci�n del contenido de la lista
						imprimeLista(ptrInicial);
					}//Cierre del if eliminar dato
					else{
						printf("\n\nel dato %c NO es el primero de la lista\n\n",elemento);
					}//Cierre del else eliminar dato
				}//Cierre del if lista no vac�a		
				else{	
					printf("\nLA LISTA ESTA VACIA...\n\n");
				}//Cierre del else lista no vac�a
			break;

			//Opcion 5 del men� (eliminar EL �LTIMO nodo de la lista) - PILA			
			case 5:
				//Evaluar si la lista no est� vac�a entonces pedir dato a eliminar
				if(!estaVacia(ptrInicial)){
					printf("Introduzca el dato a eliminar: ");
					scanf("%s", &elemento);
					//Evaluar si el dato existe en la lista entonces eliminarlo
					if(eliminar_pila(&ptrInicial, elemento)){
						printf("\n\ndato %c eliminado.\n\n", elemento);
						//Presentaci�n del contenido de la lista
						imprimeLista(ptrInicial);
					}//Cierre del if eliminar dato
					else{
						printf("\n\nel dato %c NO es el ultimo de la lista\n\n",elemento);
					}//Cierre del else eliminar dato
				}//Cierre del if lista no vac�a
				else{
						printf("\nLA LISTA ESTA VACIA...\n\n");
				}//Cierre del else lista no vac�a
			break;
			
			case 6:	
				printf("\n\nFIN DE LA APLICACION...\n\n");
			break;
		
			default:
				printf("\nOpcion no considerada. Escoja una opcion entre 1 y 6...\n");
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

// Inserta un nuevo valor dentro de la lista en orden ascendente
void insertar_orden_ascendente(ptrNodoLista *ptrS, char valor){
	//Apuntador a un nuevo nodo
	ptrNodoLista ptrNuevo;  
	//Apuntador a un nodo previo de la lista
	ptrNodoLista ptrAnterior;
	//Apuntador al nodo actual de la lista  
	ptrNodoLista ptrActual; 

	//Asignar memoria din�micamente para crear un nuevo nodo
	ptrNuevo = (NodoLista *)malloc(sizeof(NodoLista)); 

	if (ptrNuevo != NULL){ //Es espacio disponible 
		ptrNuevo->dato = valor; //Coloca el valor en el nodo 
		ptrNuevo->ptrSiguiente = NULL; //El nodo no se liga a otro nodo 
		
		ptrAnterior = NULL;
		ptrActual = *ptrS;
		
		//Ciclo para localizar la ubicaci�n correcta en la lista 
		while ( ptrActual != NULL && valor > ptrActual->dato ) {
			ptrAnterior = ptrActual; // entra al ... 
			ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo 
		}//Cierre del while	
		
		//Inserta un nuevo nodo al principio de la lista 		
		if (ptrAnterior == NULL) {
			ptrNuevo->ptrSiguiente = *ptrS;
			*ptrS = ptrNuevo;
		} //Cierre de if
		else {//inserta un nuevo nodo entre ptrAnterior y ptrActual 
			ptrAnterior->ptrSiguiente = ptrNuevo;
			ptrNuevo->ptrSiguiente = ptrActual;
		} //Cierre del else 
	}//Cierre del if
	else {
		printf( "No se inserto %c. No hay memoria disponible.\n", valor );
	}//Cierre del else
}//Cierre de la funci�n insertar dato de manera ordenada ascendentemente

//Declaraci�n y desarrollo de la funci�n de presentaci�n de la lista
void imprimeLista(ptrNodoLista ptrActual){
	printf("\nLA LISTA ES:\n\n");
	//Ciclo que recorre la lista desde el nodo cabecera hasta el �ltimo nodo
	while(ptrActual != NULL){
		printf("%c -> ", ptrActual->dato);
		ptrActual = ptrActual->ptrSiguiente;
	}//Cierre del ciclo que recorre la lista
	printf("NULL\n\n");
} //Cierre de la funci�n imprimeLista

//Declaraci�n y desarrollo de la funci�n de evaluaci�n de lista vac�a
int estaVacia(ptrNodoLista ptrS){
	//El apuntador actual es nulo
	return ptrS == NULL;
} //Cierre de la funci�n estaVacia

//Declaraci�n y desarrollo de la funci�n de eliminaci�n de un dato en la lista - COLA
char eliminar_cola(ptrNodoLista *ptrS, char valor){
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
} //Cierre de la funci�n eliminar primer dato de la lista - COLA

//Declaraci�n y desarrollo de la funci�n de eliminaci�n de un dato en la lista -PILA
char eliminar_pila(ptrNodoLista *ptrS, char valor){
	//Declaraci�n de un apuntador a un nodo previo de la lista
	ptrNodoLista ptrAnterior;
	//Declaraci�n de un apuntador al nodo actual de la lista
	ptrNodoLista ptrActual;
	//Declaraci�n de un apuntador a un nodo temporal
	ptrNodoLista tempPtr;

	ptrNodoLista ptrCabecera;

	ptrCabecera = *ptrS;

	//Evaluar si el dato est� en el primer nodo de la lista
	if(valor == (*ptrS)->dato && (*ptrS)->ptrSiguiente == NULL){
		//Asignar el primer nodo de la lista al nodo temporal
		tempPtr = *ptrS;
		//Asignar a la cabecera de la lista el apuntador al siguiente nodo de la lista
		*ptrS = (*ptrS)->ptrSiguiente;
		//Liberar la memoria que ocupa el nodo temporal
		free(tempPtr);
		//Retornar el dato a la instrucci�n donde se invoc� la funci�n eliminar
		return valor;
	}
	//De lo contrario, si el dato no est� en el primer nodo de la lista
	else{
		//Asignar el nodo inicial (cabecera) al apuntador de nodo anterior
		ptrAnterior = *ptrS;
		//Asignar la direcci�n del miembro apuntador del nodo inicial al apuntador actual
		ptrActual = (*ptrS)->ptrSiguiente;

		//Ciclo que recorre la lista hasta encontrar el nodo a eliminar
		while(ptrActual->ptrSiguiente != NULL && ptrActual->dato != valor){
			ptrAnterior = ptrActual;
			ptrActual = ptrActual->ptrSiguiente;
		}//Cierre del ciclo de recorrido de la lista hasta encontrar el nodo a eliminar

		//Evaluar si el el nodo actual no es la cabecera
		if(ptrActual->ptrSiguiente == NULL && ptrActual->dato == valor){
			//Asignar al nodo temporal el apuntador al nodo actual
			tempPtr = ptrActual;
			//Asingar al apuntador miembro del nodo anterior la direcci�n del apuntador al nodo siguiente
			ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
			//Liberar la memoria que ocupa el nodo temporal
			free(tempPtr);
		
		*ptrS = ptrCabecera;
		//Retornar el dato que conten�a el nodo eliminado
		return valor;
		}//Cierre del if cabecera nodo actual
	}//Cierre del else
	
	return '\0';
} //Cierre de la funci�n eliminar_pila

