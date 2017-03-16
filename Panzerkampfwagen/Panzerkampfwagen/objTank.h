//#ifndef objTank_HEADER
//#define objTank_HEADER
#pragma once

#include"includeLibs.h"
#include "textureDeclare.h"
#include "objProjec.h"

class objTank
{
public:
	double x_pos;
	double y_pos;

	int angle;

	bool facingleft;
	bool directionchanged = false;

	sf::Sprite bodySprite;
	sf::Sprite armSprite;

	textureDeclare* texDec;

	std::vector <objProjec> mainProj;

	objTank(double dx_pos, double dy_pos, textureDeclare* texDecRef)
	{
		texDec = texDecRef;
		x_pos = dx_pos;
		y_pos = dy_pos;
		setDefaultTexture();
		changePos();
		facingleft = true;
		mainProj.push_back(objProjec(x_pos, y_pos, 300, 300 * -1, 200, texDec));
	}

	void setDefaultTexture()
	{
		bodySprite.setTexture(texDec->textures["RedLeft"]);
		armSprite.setTexture(texDec->textures["RedArm"]);
		bodySprite.setOrigin(14, 26);
		bodySprite.setScale(1.0f, 1.0f);
		armSprite.setOrigin(22, 2);
		armSprite.setScale(1.0f, 1.0f);
	}

	void changePos()
	{
		bodySprite.setPosition(x_pos, y_pos);
		armSprite.setPosition(x_pos, y_pos);
	}

	void moveTank()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			x_pos += -1;
			bodySprite.setTexture(texDec->textures["RedLeft"]);
			if (facingleft == false){
				directionchanged = true;
			}
			facingleft = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			x_pos += 1;
			bodySprite.setTexture(texDec->textures["RedRight"]);
			if (facingleft == true){
				directionchanged = true;
			}
			facingleft = false;
		}
		if (directionchanged == true){
			if (armSprite.getRotation() <= 180){
				armSprite.setRotation(180 - armSprite.getRotation());
			}
			if (armSprite.getRotation() > 180){
				armSprite.setRotation(540 - armSprite.getRotation());
			}
			directionchanged = false;
		}
	}

	void moveArm()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && armSprite.getRotation() != 90){
			if (facingleft == true){
				armSprite.rotate(1);
			}
			if (facingleft == false){
				armSprite.rotate(-1);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && armSprite.getRotation() != 270){
			if (facingleft == true){
				armSprite.rotate(-1);
			}
			if (facingleft == false){
				armSprite.rotate(1);
			}
		}
		angle = armSprite.getRotation();
		if (angle > 90 && angle <= 180){
			angle = 180 - angle;
		}
		else if (angle > 180 && angle <= 270){
			angle = (angle - 180) * -1;
		}
		else if (angle > 270 && angle <= 360){
			angle = (360 - angle) * -1;
		}
		std::cout << angle << std::endl;
	}
};

//#endif