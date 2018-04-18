#ifndef ASTEROIDE_H
#define ASTEROIDE_H



class asteroide{
public:
	//(borrar?) nodo *nuevo;
	float x, y;  
	float Vx, Vy;
	float angle;
	float radio;
		
	asteroide(void);
	~asteroide(void);
	void Dibuja();
	//void GenerateLocation();
	//void SetSpeed();
	//void SetRadio(float r);
	void Move();
	float GetX();
	float GetY();
	float GetRadio();
	float GetAngle();
	float GetVx();
	float GetVy();
	void colisionnave();
	void nuevoasteroide();
	int colisionbullet(float i, float j);
};

#endif

/*
int vida;               // vida del asteroide
unsigned int fragmentos;// cuando se destruye, en cuantos fragmentos se
//   descompone el asteroide
float size;           // tamano del asteroide (usado para escalarlo)

void reset();
void add_ang();
void rest_ang(); */
