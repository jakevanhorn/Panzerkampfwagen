#include "textureDeclare.h"

class objProjec
{
public:
	string name;
	double x_pos;
	double y_pos;
	double x_velocity;
	double y_velocity;
	double y_accel;
	double x_posC;
	double y_posC;
	double x_velocityC;
	double y_velocityC;
	double y_accelC;
	int type = 0;
	int testAir = 0;
	Clock clock;
	Time time;

	textureDeclare texDec;
	Sprite projectile;

	objProjec()
	{
		projectile.setPosition(x_pos, y_pos);
	}

	void projecReset(double tx_pos, double ty_pos)
	{
		x_pos = tx_pos;
		y_pos = ty_pos;
		x_velocity = x_velocityC;
		y_velocity = y_velocityC;
		y_accel = y_accelC;
		projectile.setPosition(x_pos, y_pos);
	}

	void moveProj(Time time1)
	{
		x_pos += (x_velocity * time1.asSeconds());
		y_velocity += (y_accel * time1.asSeconds());
		y_pos += (y_velocity * time1.asSeconds());
		projectile.setPosition(x_pos, y_pos);
		if (testAir == 0){
			projectile.setTexture(texDec.fireball);
		}
		if (testAir == 1){
			projectile.setTexture(texDec.fireball);
		}
	}

	void testOut(double tx_pos,double ty_pos)
	{
		if (x_pos > 790){
			projecReset(tx_pos, ty_pos);
			testAir = 0;
		}
	}
};