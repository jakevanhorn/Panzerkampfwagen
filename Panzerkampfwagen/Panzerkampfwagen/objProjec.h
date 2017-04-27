//#ifndef objProjec_HEADER
//#define objProjec_HEADER
#pragma once

/**/

#include"includeLibs.h"
#include "textureDeclare.h"

class objProjec
{
public:
	std::string name;
	double x_pos; // X and Y pos for the projectile
	double y_pos;
	double powerScale = 300; // Changes initial velocity from launch
	double x_velocity; // X and Y velocity for the projectile 
	double y_velocity;
	double y_accel; // Allows for gravity and other acceleration in the Y direction
	double x_velocityC; // These three values allow for reseting of the velocity and acceleration values if needed
	double y_velocityC;
	double y_accelC;
	int type = 0; // Will be used if there are multiple types of projectiles
	int testAir = 0; // Value that represents whether or not the projectile is moving
	sf::Clock clock; // 
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

	void changeVel(int angle, bool facingleft)
	{
		double xv;
		double yv;
		bool down = false;
		if (angle < 0){
			down = true;
			angle *= -1;
		}
		xv = powerScale * cos(angle * (3.14159265 / 180));
		yv = powerScale * sin(angle * (3.14159265 / 180));
		if (facingleft == true){ xv *= -1; }
		if (down == false){ yv *= -1; }
		x_velocity = xv;
		y_velocity = yv;
	}
	
	void shootProj(double tx_pos, double ty_pos, int angle, bool facingleft)
	{
		if (testAir != 1) {
			projecReset(tx_pos, ty_pos);
			changeVel(angle, facingleft);
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

	void changePower()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &!sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			powerScale += 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &!sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			powerScale -= 1;
		}
		std::cout << powerScale << std::endl;
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