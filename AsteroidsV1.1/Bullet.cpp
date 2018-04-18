#include "Bullet.h"
#include <stdlib.h>
#include "glut.h"
#include <time.h>
#include <math.h>


const double PI=3.1415926;


extern float xnave,ynave,angnave;


Bullet::Bullet(void){
bx=xnave;
by=ynave;
a=angnave;
const double PI=3.1415926;
float V=2.0;
vx=V*cos(a);
vy=V*sin(a);
}


Bullet::~Bullet(void){}

void Bullet::Dibuja (){
glColor3ub(255,255,255);
glTranslatef(bx,by,0);
glutSolidSphere(0.5,20,20);
glTranslatef(-bx,-by,0);
glEnd();
}

/*(borrar) void Bullet::SetPosition(){
bx=xnave;
by=ynave;
a=angnave;
}*/

float Bullet::GetX(){ return bx; }

float Bullet::GetY(){ return by; }

/* (borrar) void Bullet::SetV(){
const double PI=3.1415926;
float V=(((float)rand())/(float)RAND_MAX);
vx=V*cos(a);
vy=V*sin(a);
}*/

void Bullet::Move(){
bx+=vx;
by+=vy;
if (bx>35) bx=-35;
if (bx<-35) bx=+35;
if (by>30) by=-30;
if (by<-30) by=+30;
}
