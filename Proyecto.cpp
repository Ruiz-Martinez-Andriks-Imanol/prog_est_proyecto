/* Autor: Andriks Imanol Ruiz Martínez Realizado: 15/05/2022
Escuela: Universidad del Valle de Mexico Campus Villahermosa
Materia: Programación Estructrada
Ciclo: 01/2022

Este es un programa de funciones, ciclos y condicionales en Lenguaje C de la materia de Programación Estructurada
Muestra el uso de:

    -Variables enteras, flotantes y en cadena
    -printf para mostrar mensajes y variables
    -fgets
    -scanf
    -El uso de include para las librerías
    -Librerías de la función string.h
    -Uso de condicionales
    -Archivos en cpp y tipo Header
    -#define MAX
    -Ciclos
    -fflush
    -Funciones
    -FILE: open/close
    -Comentarios para la documentación interna del programa
	*/
#include<stdio.h>
#include<stdlib.h>
#include"milibreria.h"
//Declaraciones globales
#define MAX 20
struct equipo {
	int series;
	char tipo[10];
	char modelo[36];
	char resguardo[30];
	char edificio[10];
	char area[17];
};
int n=0; //Variable que dice cuantos equipos hay en el arreglo
//Prototipos
int menu();
void agregar(struct equipo x[]);
void imprimir(struct equipo x[], int tipo);
void buscar(struct equipo x[]);
void guardar(struct equipo x[]);
void cargar(struct equipo x[]);
void reasignar(struct equipo x[]); 
//main
int main(){
	int op;
	struct equipo grupo[MAX];
	do{
		op=menu();
		switch(op){
			case 0: printf("Adios..\n");
				break;
			case 1: agregar(grupo);
				break;
			case 2: imprimir(grupo,0);
				break;
			case 3: imprimir(grupo,1);
				break;
			case 4: imprimir(grupo, 2);
				break;
			case 5:buscar(grupo);
				break;
			case 6:reasignar(grupo);
				break;
			case 7:guardar(grupo);
				break;
			case 8:cargar(grupo);
				break;
		}
	}while(op!=0);
	return 0;
}
//funciones
int menu(){
 	int opcion;
	printf("-------- MENU PRINCIPAL ---------\n");
	printf("0. Salir \n");
	printf("1. Agregar equipo: \n");
	printf("2. Lista de todos los equipos: \n");
	printf("3. Lista de las PCs: \n");
	printf("4. Lista de las Laptops: \n");
	printf("5. Buscar el equipo asignado a un administrativo: \n");
	printf("6. Reasignar equipo: \n");
	printf("7. Guardar Archivos: \n");
	printf("8. Cargar Archivos: \n");
	printf("--------------------------------------\n");
	opcion=leerd("Selecciona una opcion: ",0,8);
	return opcion;
}
void agregar(struct equipo x[]){
	int pregunta;
	while(n<MAX){
		x[n].series=leerd("Serie: ",0,999999);
		leersd("Tipo: 1.Laptop o 2. PC: ",x[n].tipo,1,2);
		leers("Modelo: ", x[n].modelo,36);
		leers("Resguardo: ", x[n].resguardo,30);
		leers("Edificio: ", x[n].edificio,10);
		leers("Area: ", x[n].area,17);
		n++; //hay que validar
		pregunta=leerd("¿Agregar otro equipo? (1-Si, 0-No): ", 0, 1);
		if (pregunta==0) {
			break;
		}
	}
	if(n==MAX){
		printf("Arreglo lleno!!!\n");
		system("PAUSE");
	}
}
//La funcion imprimir el parametro tipo se le indica que va a imprimir
//0 a todos, 1 pc, 2 laptop
void imprimir(struct equipo x[], int tipo){
	char mensaje[20];
	switch(tipo){
		case 0: strcpy(mensaje, "TOTALES	");
			break;
		case 1: strcpy(mensaje, "POR PC");
			break;
		case 2: strcpy(mensaje, "POR LAPTOP");
			break;	
	}
	printf("----------------- EQUIPOS %s ----------------------------\n", mensaje);
	printf("NO. EQUIPO\t\tNO.SERIE\tTIPO\t\t\tMODELO          \t\tRESGUARDO \t\t\tEDIFICIO       \t\tAREA\n");
	printf("----------------------------\n");
	for (int i=0;i<n;i++){ 
		switch(tipo){
			case 0: printf("%2d \t\t\t%d   \t\t%-30s%-30s%-30s%-30s%-30s \n",i+1,x[i].series,x[i].tipo,x[i].modelo,x[i].resguardo,x[i].edificio,x[i].area);
				break;
			case 1: if(strcmp(x[i].tipo,"PC")==0){
					printf("%2d \t\t\t%d   \t\t%-30s%-30s%-30s%-30s%-30s \n",i+1,x[i].series,x[i].tipo,x[i].modelo,x[i].resguardo,x[i].edificio,x[i].area);
			}
				break;
			case 2: if(strcmp(x[i].tipo,"Laptop")==0){
					printf("%2d \t\t\t%d    \t\t%-30s%-30s%-30s%-30s%-30s \n",i+1,x[i].series,x[i].tipo,x[i].modelo,x[i].resguardo,x[i].edificio,x[i].area);
			}
			break;
		}
	}
	printf("----------------------------\n");
		system("PAUSE");
} 
void buscar(struct equipo x[]) {
	//Pedir el dato
	char nombre[30];
	int busca=0;
	leers("Buscar equipo asignado: ", nombre,30);
		for (int i=0;i<n;i++){	
			if(strcmp(nombre,x[i].resguardo)==0){
					busca=1;
					printf("NO. EQUIPO\t\tNO.SERIE\tTIPO\t\t\tMODELO          \t\tRESGUARDO \t\t\tEDIFICIO       \t\tAREA\n");
					printf("%2d \t\t\t%d   \t\t%-30s%-30s%-30s%-30s%-30s \n",i+1,x[i].series,x[i].tipo,x[i].modelo,x[i].resguardo,x[i].edificio,x[i].area);
					break;
			}	
		}
		if(busca==0){
			printf("No se encuentra\n");
		}
		system("PAUSE");
	}
void reasignar(struct equipo x[]){
	//Pedir el dato
	int ser;
	int busca=0;
	ser=leerd("Serie: ",0,999999);
		for (int i=0;i<n;i++){	
			if(ser==x[i].series){
					busca=1;
					printf("NO. EQUIPO\t\tNO.SERIE\tTIPO\t\t\tMODELO          \t\tRESGUARDO \t\t\tEDIFICIO       \t\tAREA\n");
					printf("%2d \t\t\t%d   \t\t%-30s%-30s%-30s%-30s%-30s \n",i+1,x[i].series,x[i].tipo,x[i].modelo,x[i].resguardo,x[i].edificio,x[i].area);
					leers("Cambiar Resguardo: ", x[i].resguardo,30);
					break;
			}	
		}
		if (busca==0){
			printf("No existe\n");
		}	
		system("PAUSE");
}	
	//Guardar los datos como arreglos de estructuras en un archivo binario
void guardar(struct equipo x[]){
	FILE *f;
	f=fopen("Equipos.dat","w");
	if(f==NULL){
		printf("Error al tratar de guardar el archivo\n");
	}
	else {
		for(int i=0;i<n;i++){
			fwrite(&x[i],sizeof(x[i]),1,f);
		}
		fclose(f);
		printf("--->Se guardaron %d registro\n",n);
		system("PAUSE");
	}
}
//Leer el archivo binario y cargarlo a larreglo de estructuras
void cargar(struct equipo x[]){
	FILE *f;
	f=fopen("Equipos.dat","r");
	n=0;
	if(f==NULL){
		printf("Error al intentar a cargar los datos!!!\n");
	}
	else {
		printf("Leyendo.............!\n");
		while(fread(&x[n],sizeof(x[n]),1,f)==1){
			n++;
			printf("%2d\t\t%d\t%-30s\t%-30s\t%-30s\t%-30s%-30s\n",n,x[n-1].series,x[n-1].tipo,x[n-1].modelo,x[n-1].resguardo,x[n-1].edificio,x[n-1].area);
		}
		fclose(f);
		printf("--->%d registros leidos\n",n);
		system("PAUSE");
	}
}

