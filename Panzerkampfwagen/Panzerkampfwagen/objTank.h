#include "objProjec.h"

class objTank
{
public:
	double x_pos;
	double y_pos;

	int angle;

	bool facingleft;
	bool directionchanged = false;

	Sprite bodySprite;
	Sprite armSprite;

	textureDeclare texDec;

	objProjec testProj = { x_pos, y_pos, 300, 300 * -1, 200 };

	//vector <objProjec> mainProj;

	objTank(double dx_pos, double dy_pos)
	{
		x_pos = dx_pos;
		y_pos = dy_pos;
		setDefaultTexture();
		changePos();
		facingleft = true;
	}

	void setDefaultTexture()
	{
		bodySprite.setTexture(texDec.player1lefttexture);
		armSprite.setTexture(texDec.arm1texture);
		bodySprite.setOrigin(14, 26);
		bodySprite.setScale(1.0f, 1.0f);
		armSprite.setScale(1.0f, 1.0f);
		armSprite.setOrigin(22, 2);
	}

	void changePos()
	{
		bodySprite.setPosition(x_pos, y_pos);
		armSprite.setPosition(x_pos, y_pos);
	}

	void moveTank()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left) &! Keyboard::isKeyPressed(Keyboard::Right)){
			x_pos += -1;
			bodySprite.setTexture(texDec.player1lefttexture);
			if (facingleft == false){
				directionchanged = true;
			}
			facingleft = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) &! Keyboard::isKeyPressed(Keyboard::Left) ){
			x_pos += 1;
			bodySprite.setTexture(texDec.player1righttexture);
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
		if (Keyboard::isKeyPressed(Keyboard::Up)){
			if (facingleft == true){
				armSprite.rotate(1);
			}
			if (facingleft == false){
				armSprite.rotate(-1);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)){
			if (facingleft == true){
				armSprite.rotate(-1);
			}
			if (facingleft == false){
				armSprite.rotate(1);
			}
		}
		angle = armSprite.getRotation();
	}
};