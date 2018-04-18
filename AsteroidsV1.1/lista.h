#include "asteroide.h"
#include <stdlib.h>
#include "glut.h"
#include <time.h>
#include <math.h>
#include "Bullet.h"


#ifndef LISTA_H
#define LISTA_H


struct Nodo{
	asteroide ast;
	struct Nodo *next;};

struct Nodob{
	Bullet bul;
	struct Nodob *next;};

class lista{

private:
	Nodo *flecha;
	int elementos;
	Nodob *flechab;
	int elementosb;
public:
	lista();
	void insertarasteroide();
	void insertarasteroide(float x,float y,float Vx,float Vy,float a, float r);
	void imprimir();			//Dibuja asteroides y bala
	void mover();				//mueve tanto los ateroides como la bala
	void colisiones();			//mira colisiones asteroide-nave
	void eliminarasteroide();
	void añadir();				//crea asteroide cada x tiempo
	void insertarbullet();
	void quitarbullet();
	void bulletvsasteroide();	//mira colision bala-asteroide
	
	
	
	/*ListaEnlazada();
	void Imprimir();
	void InsertarEnCola(int x);
	Nodo* BuscarElem(int x);
	int NumElementos();
	int Vacia();
	*/
};


#endif
