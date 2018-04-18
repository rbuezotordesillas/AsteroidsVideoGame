#ifndef NAVE_H
#define NAVE_H

class Nave{

private:
	float x;	//coordenadas del centro
	float y;
	float z; 
	float a;	//angulo
	float Vx;	//velocidad
	float Vy;
	int r, g, b; //color

public:
	Nave(void);
	~Nave(void);
	void SetPos(float i,float j);
	//(borrar?)void SetV(float i, float j);
	//(borrar?)void SetAng(float i);
	//(borrar?)void SetColor(float i);
	void Dibuja();
	void Rota(float i);
	void thrust(float i);
	void Move();
	void Teleport();		//cambia a una posicion aleatoria 
	float GetX();
	float GetY();
	float GetAngle();
	void Cambiarcolornave(int i, int j, int k);		//para cambiar el color de la nave cuando colisiona con un asteroide
};

#endif