#ifndef BULLET_H
#define BULLET_H

class Bullet{

public:
	float bx;
	float by;
	float vx,vy;
	float a;

	void Dibuja();
	//(borrar) void Erase();
	//(borrar) void SetPosition(); 
	//(borrar) void SetV();
	void Move();
	float GetX();
	float GetY();
	Bullet(void);
	~Bullet(void);
};

#endif 