#include "lista.h"
#include <math.h>
#include "Nave.h"
#include "asteroide.h"
#include <stdio.h>
#include <time.h>
#include "glut.h"


lista b;
Nave n;

int aux_rot=0, aux_thrust=0;
float xnave;
float ynave;
float angnave;
int nivel;
int colorazo,tiempazo;
int timebullet;

float PI = 3.1415926;

//Declaraciones
void OnDraw(void);
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y);
void OnKeyboardUp(unsigned char key, int x_t, int y_t);
void OnSpecKeyboardDown(int key, int x, int y);
void OnSpecKeyboardUp(int key, int x, int y);

//(borrar?)float distancia(float x, float y, float u, float v);



int main(int argc,char* argv[]){
	
	srand(time(0));

	//Inicializar el gestor de ventanas GLUT y crear la ventana 
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Asteroids");

	//Habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	//(borrar?)glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);
	
	//Callbacks
	glutDisplayFunc(OnDraw); 
	glutTimerFunc(25,OnTimer,0);
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);
	//(borrar?)glutSpecialFunc(OnSpecKeyboardDown);
	//(borrar?)glutKeyboardUpFunc(OnSpecKeyboardUp);
		
	//Inicialización de los datos de la simulación
	b.insertarasteroide();
	nivel = 5;				//por que no se pone al principio lo de nivel,colorazo y las de nave?
	colorazo = 0;
	printf("\nNivel inicial: 5");
	//aux_nx=0; aux_ny=0; aux_na=0;
	xnave=0;ynave=0;angnave=0; 	

	//Pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();
	return 0;
} 

void OnDraw(void){
	//Borrado de la pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,0,80, // posicion del ojo
	0.0, 0, 0.0, // hacia que punto mira
	0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	
	//(borrar?)pintar marco
	
	//pintar cositas
	n.Dibuja();
	b.imprimir();
		
	//Al final, cambiar el buffer (redibujar)
	glutSwapBuffers();} 

void OnTimer(int value){
	
	n.Move();
	n.Rota(aux_rot*(1/(2*PI)));
	n.thrust(aux_thrust*0.05);
	
	b.mover();
	b.añadir();
	b.bulletvsasteroide();

	xnave = n.GetX();
	ynave = n.GetY();
	angnave = n.GetAngle();

	b.colisiones();
	n.SetPos(xnave, ynave);
	
	
	if (colorazo == 1){			//colorazo es =1 cuando ha habido colision nave-asteroide
		tiempazo = time(0);
		n.Cambiarcolornave(0, 133,0);	//nave cambia de color a verde durante unos segundos al colisionar con asteroide
		colorazo = 0;}

	if (time(0) - tiempazo > 1){ n.Cambiarcolornave(255, 0, 0); }

	if (clock() - timebullet > 700) b.quitarbullet();		//desaparece la bala después de un cierto tiempo
	


	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();

}

void OnKeyboardDown(unsigned char key, int x_t, int y_t){ 
	if (key == 'a' || key == 'A') aux_rot = 1;		//rotar a la izquierda
	if (key == 'd' || key == 'D') aux_rot = -1;		//rotar a la derecha
	if (key == 'w' || key == 'W') aux_thrust = 1;	
	if (key == 't' || key == 'T') n.Teleport();
	if (key == 'l' || key == 'L') b.insertarasteroide();
	if (key == 'K' || key == 'k') b.eliminarasteroide();
	if (key == '+' && nivel > 1) {nivel--; printf("\nnivel %d", 11 - nivel);}
	if (key == '-' && nivel < 10){ nivel++; printf("\nnivel %d", 11 - nivel); }
	if (key == ' '){ xnave = n.GetX(); ynave = n.GetY(); angnave = n.GetAngle(); b.insertarbullet(); };

	glutPostRedisplay();
}
void OnKeyboardUp(unsigned char key, int x_t, int y_t){
	if (key=='a'||key=='A') aux_rot = 0;
	if (key=='d'||key=='D') aux_rot=0;
	if (key=='w'||key=='W') aux_thrust=0;
	
	glutPostRedisplay();
}

