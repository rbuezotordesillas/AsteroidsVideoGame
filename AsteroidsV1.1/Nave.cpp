#include "Nave.h"
#include <stdlib.h>
#include "glut.h"
#include <math.h>
#include <time.h>

extern float PI;

Nave::Nave(void){
	x = 0;	y = 0; z = 0;
	Vx = 0; Vy = 0;
	r = 255; g = 0; b = 0;
	a = 0;
}

Nave::~Nave(void){}

void Nave::SetPos(float i, float j){x=i;y=j;z=0;}

//(borrar) void Nave::SetV(float i, float j){Vx=i;Vy=j;}

//(borrar) void Nave::SetAng(float i){a=i;}

void Nave::Dibuja(){
	float size=3;
	glColor3ub(r,g,b);
	glBegin(GL_POLYGON);
	glVertex3f(x+0.7*size*cos(a),y+0.7*size*sin(a),0.0f);
	glVertex3f(x-0.3*size*cos(a+PI/4),y-0.3*size*sin(a+PI/4),0.0f);
	glVertex3f(x,y,0.0f);
	glVertex3f(x-0.3*size*cos(a-PI/4),y-0.3*size*sin(a-PI/4),0.0f);
	glEnd();
}

void Nave::Rota(float i){a=a+i;}

void Nave::thrust(float i){	Vx=Vx+i*cos(a);	Vy=Vy+i*sin(a);}

void Nave::Move(){
	x=x+Vx;
	y=y+Vy;
	if (Vx>.0) Vx=Vx-0.02*Vx;	//para ir frenando
	if (Vy>.0) Vy=Vy-0.02*Vy;
	if (Vx<.0) Vx=Vx-0.02*Vx;
	if (Vy<.0) Vy=Vy-0.02*Vy;
	if (Vx>1.5) Vx=1.5;			//limitadores de velocidad
	if (Vy>1.5) Vy=1.5;	
	if (Vx<-1.5) Vx=-1.5;
	if (Vy<-1.5) Vy=-1.5;
	if (x>37) x=-37;			//aparecer en el otro lado de pantalla

	if (x<-37) x=+37;
	if (y>30) y=-30;
	if (y<-30) y=+30;
}

void Nave::Teleport(){
	//(borrar) srand(time(0));
	x=37-rand()%74;
	y=30-rand()%60;
}

void Nave::Cambiarcolornave(int r1, int g1, int b1){ r = r1;	g = g1;	b = b1;}

float Nave::GetX(){return x;}

float Nave::GetY(){return y;}

float Nave::GetAngle(){return a;}