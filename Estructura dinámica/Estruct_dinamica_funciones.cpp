/*Captura y presentaci�n*/

#include<stdio.h>
#include<stdlib.h>

//Prototipado de un registro o estructura din�mica
struct empleado{
	int id;
	float salario;
};

//Definici�n de un alias para la estructura empleado
typedef struct empleado Usuario;

//Definici�n de un alias para un apuntador a la estructura empleado
typedef Usuario *ptrUsuario;

//Prototipado de las funciones
void capturar_registro(ptrUsuario *User1, int dato_id1, float dato_salario1);
void presentar_registro(ptrUsuario User2);

int main(){
	
	//Declaraci�n de una estructura din�mica
	ptrUsuario Cliente;
	
	//Declaraci�n de variables para la captura de datos
	int dato_id; float dato_salario;
	
	//Inicializaci�n de una estructura din�mica
	Cliente=NULL;
	
	//Inicializaci�n de variables de captura de datos
	dato_id=0; dato_salario=0,0;
	
	//Asignaci�n de memoria a la estructura de manera din�mica
	Cliente=(Usuario *)malloc(sizeof(Usuario));
	
	//Iniccializaci�n de las variables de la estructura
	Cliente->id=0;
	Cliente->salario=0,0;
	
	//Captura de datos desde el teclado
	printf("\nINGRESO DE DATOS DE UN CLIENTE\n");
	printf("\nId: ");
	scanf("%d",&dato_id);
	printf("\nSalario: ");
	scanf("%f",&dato_salario);
	
	//Asignaci�n de los datos al registro
	capturar_registro(&Cliente, dato_id, dato_salario);
	
	//Presentaci�n del contenido de la estructura din�mica
	printf("\nCONTENIDO DE UNA ESTRUCTURA DINAMICA O REGISTRO DE DATOS");
	presentar_registro(Cliente);
	
	printf("\n\n");
	system("PAUSE");
	return 0;
		
}//Cierre del bloque principal

//Funci�n de captura de los datos de una estructura din�mica
void capturar_registro(ptrUsuario *User1, int dato_id1, float dato_salario1){
	
	//Declaraci�n de un apuntador tipo estructura din�mica
	ptrUsuario ptrNuevo;

 	//Asignaci�n de los datos al apuntador de la estructura din�mica
 	ptrNuevo->id = dato_id1;
 	ptrNuevo->salario = dato_salario1;
 	
	 //Asignaci�n del apuntador a la estructura din�mica
 	*User1 = ptrNuevo;

} //Cierre funci�n capturar_registro

//Funci�n de presentaci�n de una estructura din�mica
void presentar_registro(ptrUsuario User2){
 printf("\nId: %d", User2->id);
 printf("\nSalario: %f", User2->salario);
} //Cierre funci�n presentar_registro 
