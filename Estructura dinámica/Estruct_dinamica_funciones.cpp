/*Captura y presentación*/

#include<stdio.h>
#include<stdlib.h>

//Prototipado de un registro o estructura dinámica
struct empleado{
	int id;
	float salario;
};

//Definición de un alias para la estructura empleado
typedef struct empleado Usuario;

//Definición de un alias para un apuntador a la estructura empleado
typedef Usuario *ptrUsuario;

//Prototipado de las funciones
void capturar_registro(ptrUsuario *User1, int dato_id1, float dato_salario1);
void presentar_registro(ptrUsuario User2);

int main(){
	
	//Declaración de una estructura dinámica
	ptrUsuario Cliente;
	
	//Declaración de variables para la captura de datos
	int dato_id; float dato_salario;
	
	//Inicialización de una estructura dinámica
	Cliente=NULL;
	
	//Inicialización de variables de captura de datos
	dato_id=0; dato_salario=0,0;
	
	//Asignación de memoria a la estructura de manera dinámica
	Cliente=(Usuario *)malloc(sizeof(Usuario));
	
	//Iniccialización de las variables de la estructura
	Cliente->id=0;
	Cliente->salario=0,0;
	
	//Captura de datos desde el teclado
	printf("\nINGRESO DE DATOS DE UN CLIENTE\n");
	printf("\nId: ");
	scanf("%d",&dato_id);
	printf("\nSalario: ");
	scanf("%f",&dato_salario);
	
	//Asignación de los datos al registro
	capturar_registro(&Cliente, dato_id, dato_salario);
	
	//Presentación del contenido de la estructura dinámica
	printf("\nCONTENIDO DE UNA ESTRUCTURA DINAMICA O REGISTRO DE DATOS");
	presentar_registro(Cliente);
	
	printf("\n\n");
	system("PAUSE");
	return 0;
		
}//Cierre del bloque principal

//Función de captura de los datos de una estructura dinámica
void capturar_registro(ptrUsuario *User1, int dato_id1, float dato_salario1){
	
	//Declaración de un apuntador tipo estructura dinámica
	ptrUsuario ptrNuevo;

 	//Asignación de los datos al apuntador de la estructura dinámica
 	ptrNuevo->id = dato_id1;
 	ptrNuevo->salario = dato_salario1;
 	
	 //Asignación del apuntador a la estructura dinámica
 	*User1 = ptrNuevo;

} //Cierre función capturar_registro

//Función de presentación de una estructura dinámica
void presentar_registro(ptrUsuario User2){
 printf("\nId: %d", User2->id);
 printf("\nSalario: %f", User2->salario);
} //Cierre función presentar_registro 
