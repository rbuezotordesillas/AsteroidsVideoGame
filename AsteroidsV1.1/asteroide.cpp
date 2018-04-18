#include "asteroide.h"
#include <stdlib.h>
#include <stdio.h>
#include "glut.h"
#include <time.h>
#include <math.h>

extern float xnave;
extern float ynave;
extern float angnave;
const double PI = 3.1415926;
extern int colorazo;


float distancia(float x, float y, float u, float v){	//distancia entre dos puntos
	return(sqrt((x - u)*(x - u) + (y - v)*(y - v))); }


asteroide::asteroide(void)
{
	//srand(time(0));
	float aux_x = 37- rand() % (2*37);
	float aux_y= 30- rand() % (2*30);
	while ((distancia(aux_x,aux_y,xnave,ynave))<(2*radio)){
		aux_x = 37- rand() % (2*37);
		aux_y= 30- rand() % (2*30);
	}

	x=aux_x;
	y=aux_y;
	angle = rand()/(2*PI);
	
	float V = (((float)rand()) / (2*(float)RAND_MAX));
	Vx = 0.05+V;
	Vy = 0.05+V; 

	radio = 5-rand()%3;			//valores aleatorios para tener asteroides de distintos tamaños



}


void asteroide::colisionnave(){
		if (distancia(xnave + 0.7 * 3 * cos(angnave),  ynave + 0.7* 3 * sin(angnave), x, y)< radio
	   	||  distancia(xnave - 0.3 * 3 * cos(angnave+ PI / 4), ynave - 0.3 * 3 * sin(angnave + PI / 4), x, y) < radio
		|| distancia(xnave - 0.3 * 3 * cos(angnave - PI / 4), ynave - 0.3 * 3 * sin(angnave - PI / 4), x, y) < radio){
			xnave = 0; ynave = 0;  
			colorazo = 1;
			printf("\ntoco el asteroide de radio: %f",radio); }
}

int asteroide::colisionbullet(float i, float j){
	if (sqrt((y - j)*(y - j) + (x - i)*(x - i)) < radio + 0.5){     //0.5 es el radio de la bala
		printf("\ntoco");
		return(1);
			}
	return 0;
}

void asteroide::Dibuja()
{
	glColor3ub(0,0,255); 
	glTranslatef(x,y,0);
	glutSolidSphere(radio,20,20);
	glTranslatef(-x,-y,0);
}

/*void asteroide::GenerateLocation(){
srand(time(0));
x= rand()%37;
y=rand()%30;
angle=rand()/91.02;
}*/

/*void asteroide:: SetSpeed(){
float V = (((float)rand())/(float)RAND_MAX);
Vx=V*cos(angle*PI/180);
Vy=V*sin(angle*PI/180);
}*/

//void asteroide::SetRadio(float r){	radio=r;}


void asteroide::Move()
{
x+=Vx*cos(angle);
y+=Vy*sin(angle);
if (x>35) x=-35;
if (x<-35) x=+35;
if (y>30) y=-30;
if (y<-30) y=+30;
}



float asteroide::GetX(){return x;}

float asteroide::GetY(){return y;}

float asteroide::GetRadio(){return radio;}

float asteroide::GetAngle(){return angle;}

float asteroide::GetVx(){return Vx;}

float asteroide::GetVy(){return Vy;}

asteroide::~asteroide(void){}




/*	forma irregular de asteroide
	glBegin(GL_LINE_STRIP);
	glVertex2f(1.0, 1.0);
	glVertex2f(1.8, 0.0);
	glVertex2f(1.4, -0.8);
	glVertex2f(1.0, -1.7);
	glVertex2f(-1.5, -1.0);
	glVertex2f(-1.0, 0.0);
	glVertex2f(0.0, 1.4);
	glVertex2f(1.0, 1.0);
	glEnd();*/