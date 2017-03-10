//#ifndef objProjec_HEADER
//#define objProjec_HEADER
#pragma once

#include"includeLibs.h"
#include "textureDeclare.h"

class objProjec
{
public:
	std::string name;
	double x_pos;
	double y_pos;
	double x_velocity;
	double y_velocity;
	double y_accel;
	double x_velocityC;
	double y_velocityC;
	double y_accelC;
	int type = 0;
	int testAir = 0;
	sf::Clock clock;
	sf::Time time;

	sf::Sprite projectile;

	textureDeclare* texDec;

	objProjec(double cx_pos, double cy_pos, double cx_vel, double cy_vel, double cy_acc, textureDeclare* texDecRef)
	{
		texDec = texDecRef;
		x_velocityC = cx_vel;
		y_velocityC = cy_vel;
		y_accelC = cy_acc;
		projecReset(cx_pos, cy_pos);
		setTexture(10);
		projectile.setScale(sf::Vector2f(.002, .002));
	}

	void setTexture(int type)
	{
		projectile.setTexture(texDec->textures["Fireball"]);
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
	
	void shootProj(double tx_pos, double ty_pos)
	{
		if (testAir != 1) {
			projecReset(tx_pos, ty_pos);
			testAir = 1;
			clock.restart();
			projectile.setScale(sf::Vector2f(1, 1));
		}
	}

	void moveProj()
	{
		if (testAir == 1){
			time = clock.getElapsedTime();
			x_pos += (x_velocity * time.asSeconds());
			y_velocity += (y_accel * time.asSeconds());
			y_pos += (y_velocity * time.asSeconds());
			projectile.setPosition(x_pos, y_pos);
			clock.restart();
		}
	}

	void testOut(double tx_pos,double ty_pos)
	{
		if (y_pos > 790){
			projecReset(tx_pos, ty_pos);
			testAir = 0;
			projectile.setScale(sf::Vector2f(.002, .002));
		}
	}
};

//#endif