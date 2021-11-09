/*Captura y presentación de una lista de nodos L01/07/2019 - 16:32 - Angela Díaz*/

#include <stdio.h>
#include <stdlib.h>

//Definición del nodo (estructura autoreferenciada) nodoLista
struct nodoLista{
	char dato; //varialbe para almacenar un caracter digitado por el usuario
	struct nodoLista *ptrSiguiente; //Apuntador al siguiente nodo
};

//Definición de un alias para la estructura de nodo nodoLista
typedef struct nodoLista NodoLista;

//Definición de un alias para un apuntador al nodo nodoLista
typedef NodoLista *ptrNodoLista;

//Prototipado de funciones por referencia
void insertar(ptrNodoLista *ptrS, char valor);
void imprimeLista(ptrNodoLista ptrActual);
int estaVacia(ptrNodoLista ptrS);
char eliminar(ptrNodoLista *ptrS, char valor);

int main(){
	
	//Declaración de un apuntador tipo apuntador al nodo inicial de la lista
	ptrNodoLista ptrInicial;	
	ptrInicial = NULL;

	//Variable de opción de menú
	int eleccion = 0;
	
	//Variable que almacena el dato ingresado por el usuario
	char elemento = ' ';

	//Ciclo de evaluación de la opción escogida por el usuario
	while(eleccion != 5){

		//Invocación del menú
		printf("\nMENU DE UNA LISTA DE DATOS\n");
		printf("\n1. Insertar un dato en la lista");
		printf("\n2. Presentar el contenido de la lista");
		printf("\n3. Borrar el PRIMER nodo o dato de la lista");
		printf("\n4. Borrar el ULTIMO nodo o dato de la lista");
		printf("\n5. Salir de la aplicacion\n");
		printf("\nEscoja una opcion (1/3): ");
		scanf("%d", &eleccion);

		//Evaluar la opción
		switch(eleccion){
	
			//Opción 1 del menú (insertar nodo en la lista)
			case 1:
				printf("Introduzca un caracter: ");
				scanf("%s", &elemento);
				insertar(&ptrInicial, elemento);
			break;
	
		//Opción 2 del menú (presentar nodo de la lista)
	
			case 2:
				//Evaluar si la lista no está vacía entonces pedir dato a eliminar
				if(!estaVacia(ptrInicial)){
					//Presentación del contenido de la lista
					imprimeLista(ptrInicial);
				}//Cierre del if lista no vacía
				else{
					printf("\nLA LISTA ESTA VACIA...\n\n");
				}//Cierre del else lista no vacía
			break;
		
			//Opción 3 del menú (eliminar EL PRIMER nodo de la lista) - COLA
			case 3:
				//Evaluar si la lista no está vacía entonces pedir dato a eliminar
				if(!estaVacia(ptrInicial)){
					printf("Introduzca el dato a eliminar: ");
					scanf("%s", &elemento);
					//Evaluar si el dato existe en la lista entonces eliminarlo
					if(eliminar(&ptrInicial, elemento)){
						printf("\n\ndato %c eliminado.\n\n", elemento);
						//Presentación del contenido de la lista
						imprimeLista(ptrInicial);
					}//Cierre del if eliminar dato
					else{
						printf("\n\nel dato %c NO es el primero de la pila\n\n",elemento);
					}//Cierre del else eliminar dato
		
				}//Cierre del if lista no vacía
				
				else{	
					printf("\nLA LISTA ESTA VACIA...\n\n");
				}//Cierre del else lista no vacía
			break;
			
			case 5:	
				printf("\n\nFIN DE LA APLICACION...\n\n");
			break;
		
			default:
				printf("\nOpcion no considerada. Escoja una opcion entre 1 y 5...\n");
			break;
			
		} //Cierre del switch evaluar opción escogida

	} //Cierre del ciclo de evaluación de opción escogida

	printf("\n\n");
	system("PAUSE");
	return 0;
} //Cierre función principal

//Declaración y desarrollo de la función de inserción de un nuevo dato en la lista
void insertar(ptrNodoLista *ptrS, char valor){
	//Declaración de un apuntador a un nuevo nodo
	ptrNodoLista ptrNuevo;
	//Declaración de un apuntador a un nodo previo de la lista
	ptrNodoLista ptrAnterior;
	//Declaración de un apuntador al nodo actual de la lista
	ptrNodoLista ptrActual;

	//Asignar memoria dinámicamente para crear un nuevo nodo
	ptrNuevo = (NodoLista *)malloc(sizeof(NodoLista));

	//Asignar el caracter digitado al miembro dato del nodo nuevo
	ptrNuevo->dato = valor;
	//Asignar NULL al apuntador del nodo (No enlazarlo aun a la lista)
	ptrNuevo->ptrSiguiente = NULL;
	
	//Asignar NULL al apuntador que apunta al nodo previo de la lista
	ptrAnterior = NULL;
	//Asignar al apuntador actual el nodo inicial de la lista (cabecera)
	ptrActual = *ptrS;
	
	//Ciclo que identifica en qué lugar de la lista ha de insertarse el nuevo nodo
	//while(ptrActual != NULL && valor > ptrActual->dato){
	while(ptrActual != NULL){
		ptrAnterior = ptrActual;
		ptrActual = ptrActual->ptrSiguiente;
	}//Cierre dle ciclo de identificación del lugar de inserción del nuevo nodo

	//Evaluar si el nuevo nodo se inserta al principio de la lista
	if(ptrAnterior == NULL){	
		//Asignar al apuntador de la cabecera el nuevo nodo
		ptrNuevo->ptrSiguiente = *ptrS;
		*ptrS = ptrNuevo;
	}//Cierre del if de inserción al principio de la lista
	//De lo contrario, insertar en nuevo nodo entre el nodo anterior y el actual de la lista
	
	else{
		//Asignar el nuevo nodo al miembro apuntador del nodo anterior
		ptrAnterior->ptrSiguiente = ptrNuevo;
		ptrNuevo->ptrSiguiente = ptrActual;
	}//Cierre del else insertar nuevo nodo entre el anterior y el actual
	
} //Cierre de la función insertar

//Declaración y desarrollo de la función de presentación de la lista
void imprimeLista(ptrNodoLista ptrActual){
	printf("\nLA LISTA ES:\n\n");
	//Ciclo que recorre la lista desde el nodo cabecera hasta el último nodo
	while(ptrActual != NULL){
		printf("%c -> ", ptrActual->dato);
		ptrActual = ptrActual->ptrSiguiente;
	}

	printf("NULL\n\n");

} //Cierre de la función imprimeLista

//Declaración y desarrollo de la función de evaluación de lista vacía
int estaVacia(ptrNodoLista ptrS){
	//El apuntador actual es nulo
	return ptrS == NULL;
} //Cierre de la función estaVacia

//Declaración y desarrollo de la función de eliminación de un dato en la pila
char eliminar(ptrNodoLista *ptrS, char valor){
	//Declaración de un apuntador a un nodo previo de la pila
	ptrNodoLista ptrAnterior;
	//Declaración de un apuntador al nodo actual de la pila
	ptrNodoLista ptrActual;
	//Declaración de un apuntador a un nodo temporal
	ptrNodoLista tempPtr;

	//Evaluar si el dato está en el primer nodo de la pila
	if(valor == (*ptrS)->dato){
		//Asignar el primer nodo de la lista al nodo temporal
		tempPtr = *ptrS;
		//Asignar a la cabecera de la lista el apuntador al siguiente nodo de la lista
		*ptrS = (*ptrS)->ptrSiguiente;
		//Liberar la memoria que ocupa el nodo temporal
		free(tempPtr);
		//Retornar el dato a la instrucción donde se invocó la función eliminar
		return valor;
	}//Cierre del if evaluar dato al principio de la pila
	return '\0';
} //Cierre de la función eliminar
