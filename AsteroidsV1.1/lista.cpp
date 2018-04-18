#include "lista.h"
#include "asteroide.h"
#include <stdlib.h>
#include "glut.h"
#include <time.h>
#include <math.h>
#include <stdio.h>
#include "Bullet.h"


#define NULL 0

struct AsteroidData
{
	float x, y;  
	float Vx, Vy;
	float angle;
	float radio;
};

AsteroidData aux;

int tiempo=0;
extern int nivel;
extern int timebullet;

lista::lista(){
	elementos= 0;
	flecha= NULL;
	elementosb = 0;
	flechab = NULL;
}

//cada x tiempo se añade un asteroide
void lista::añadir(){
	asteroide a;
	Nodo *nuevo = new Nodo;
	
	if ((time(0)-tiempo)>nivel){
		nuevo->ast = a;
		nuevo->next = flecha;
		flecha = nuevo;
		elementos++;
		printf("\nAsteroides: %d", elementos);
		tiempo = time(0);}
	}   

//para insertar asteroide al pulsar L
void lista::insertarasteroide(){
	asteroide a;
	Nodo *nuevo = new Nodo;

	nuevo->ast = a;
	nuevo->next = flecha;
	flecha = nuevo;
	elementos++;
	printf("\nAsteroides: %d", elementos);
}

void lista::insertarasteroide(float x,float y,float Vx,float Vy,float angle, float radio){
	asteroide a;
	Nodo *nuevo = new Nodo;

	nuevo->ast = a;

	nuevo->ast.angle=angle;
	nuevo->ast.radio=radio/2;
	nuevo->ast.x=x;
	nuevo->ast.y=y;
	nuevo->ast.Vx=Vx;
	nuevo->ast.Vy=Vy;

	nuevo->next = flecha;
	flecha = nuevo;
	elementos++;
	printf("\nAsteroides: %d", elementos);
}

//eliminar asteroide al pulsar K
void lista::eliminarasteroide(){
	if (elementos > 0) {       //ANTES TENIA UN 1: OJO A VER SI PASA ALGO
		flecha = flecha->next;
		elementos--; }
	printf("\nasteroides: %d", elementos);
}

void lista::imprimir(){
	Nodo *tmp = new Nodo;
	Nodob *tmpb = new Nodob;

	tmp = flecha;
	tmpb = flechab;

	if (elementos != 0){
		while (1){
			tmp->ast.Dibuja();
			if (tmp->next != NULL) tmp = tmp->next;
			else break;}}
	else printf("\n  No tiene asteroides");


	if (elementosb != 0){
		while (1){
			tmpb->bul.Dibuja();
			if (tmpb->next != NULL) tmpb = tmpb->next;
			else break;	}}
}

void lista::mover(){
	Nodo *tmp = new Nodo;
	Nodob *tmpb = new Nodob;
	tmp = flecha;
	tmpb = flechab;

	if (elementos != 0){
		while (1){
			tmp->ast.Move();
			if (tmp->next != NULL) tmp = tmp->next;
			else break;}}
	else printf("\n  No tiene asteroides");

	if (elementosb != 0){
		while (1){
			tmpb->bul.Move();
			if (tmpb->next != NULL) tmpb = tmpb->next;
			else break;
		}	}
}

void lista::colisiones(){
	Nodo *tmp = new Nodo;
	tmp = flecha;

	if (elementos != 0){
		while (1){
			tmp->ast.colisionnave();
			if (tmp->next != NULL) tmp = tmp->next;
			else break;
		}}
	else printf("\n  No tiene asteroides");
}

void lista::insertarbullet(){
	Bullet c;
	Nodob *nuevob = new Nodob;
	if (elementosb == 0){
		nuevob->bul = c;
		nuevob->next = flechab;
		flechab = nuevob;
		elementosb++;
		timebullet = clock();}}

void lista::quitarbullet(){
	flechab=NULL;
	elementosb = 0;
}
/*
			while ((tmp->next != NULL) && (tmp->data != x)){
				tmp2 = tmp;
				tmp = tmp->next;}

			if (tmp->data == x){
					tmp2->next = tmp->next;
					elementos--;
					printf("\n  Elemento borrado");}
				else printf("\n  El numero %d no se encuentra en la lista", x);

				if (lista->data == x){ lista == tmp->next; }*/
void lista::bulletvsasteroide(){
	Nodo *tmp = new Nodo;
	Nodo *tmp2 = new Nodo;
	tmp = flecha;
	tmp2 = tmp;
	int c;
	float a, b;
	
	if (elementosb == 1 && elementos > 0){
		a = flechab->bul.GetX();
		b = flechab->bul.GetY();
		c=0;
		c = flecha->ast.colisionbullet(a, b);
		if (c) {
			//Guardar info
			aux.x=flecha->ast.GetX();
			aux.y=flecha->ast.GetY();
			aux.radio=flecha->ast.GetRadio();
			aux.Vx=flecha->ast.GetVx();
			aux.Vy=flecha->ast.GetVy();
			aux.angle=flecha->ast.GetAngle();

			flecha = flecha->next; 
			flechab = NULL;
			elementosb--;
			elementos--;
			
				if(aux.radio>2){
					insertarasteroide(aux.x,aux.y,aux.Vx,aux.Vy,aux.angle+0.75,aux.radio);
					insertarasteroide(aux.x,aux.y,aux.Vx,aux.Vy,aux.angle-0.75,aux.radio);
					}
			
			
			printf("\nasteroides: %d", elementos);
			return;}
		else{
			while (1){
				c = tmp->ast.colisionbullet(a, b);
				if (c == 1){
					//Guardar info
					aux.x=tmp->ast.GetX();
					aux.y=tmp->ast.GetY();
					aux.radio=tmp->ast.GetRadio();
					aux.Vx=tmp->ast.GetVx();
					aux.Vy=tmp->ast.GetVy();
					aux.angle=tmp->ast.GetAngle();

					flechab = NULL;
					elementosb--;
					elementos--;
					if(aux.radio>2){
					insertarasteroide(aux.x,aux.y,aux.Vx,aux.Vy,aux.angle+0.75,aux.radio);
					insertarasteroide(aux.x,aux.y,aux.Vx,aux.Vy,aux.angle-0.75,aux.radio);
					}
					printf("\nasteroides: %d", elementos);
					tmp2->next = tmp->next;

					
					return;
				}
				else if (tmp->next != NULL){ tmp2 = tmp; tmp = tmp->next; }
				else break;
			}
		}
	}
}
	
	
	


/*
void ListaEnlazada::Imprimir(){
	Nodo *tmp = new Nodo;
	tmp = lista;

	if (elementos != 0){
		printf("\n  Su lista actual es: ");
		while (1){
			printf("%d ", (*tmp).data);             // (*tmp).data equivale a tmp->data
			if (tmp->next != NULL) tmp = tmp->next;
			else break;
		}
	}
	else printf("\n  Su lista esta vacia");
}
 



void ListaEnlazada::InsertarEnCola(int x){
	Nodo *nuevo = new Nodo;
	Nodo *tmp = new Nodo;

	nuevo->data = x;
	nuevo->next = NULL;
	tmp = lista;

	if (elementos == 0) lista = nuevo;
	else{
	while (tmp->next != NULL){ tmp = tmp->next; }
	tmp->next = nuevo;
	}
	elementos++;

}

void ListaEnlazada::Borrar(int x){

	Nodo *tmp = new Nodo;
	Nodo *tmp2 = new Nodo;
	int a = 0;
	tmp = lista;

	if (elementos == 0) {printf("\n  NO se ha eliminado el numero"); return;}
		else{
			while ((tmp->next != NULL) && (tmp->data != x)){
				tmp2 = tmp;
				tmp = tmp->next;}

			if (tmp->data == x){
					tmp2->next = tmp->next;
					elementos--;
					printf("\n  Elemento borrado");}
				else printf("\n  El numero %d no se encuentra en la lista", x);

				if (lista->data == x){ lista == tmp->next; }  //probando veo que necesito esto
	}
	
}

Nodo* ListaEnlazada::BuscarElem(int x){
	Nodo* tmp = new Nodo;
	int aux=1;
	tmp = lista;

	if (elementos != 0){
		while ((tmp->next != NULL) && (tmp->data != x)){
			tmp = tmp->next;
			aux++;
		}
			if (tmp->data == x){
				printf("\n  El numero se encuentra en el puesto %d de la lista", aux);
				return(tmp); } 
			else {
				printf("\n  El numero no se encuentra en la lista");
				return (NULL);
			}
		}
		
}

int ListaEnlazada::NumElementos(){
	return (elementos);}                     

int ListaEnlazada::Vacia(){
	if (elementos != 0)  return 1;                   
	else return 0;
}

*/