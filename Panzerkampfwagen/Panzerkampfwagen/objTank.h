#include "objProjec.h"

class objTank
{
public:
	string name;
	double x_pos;
	int y_pos;
	int angle;
	Sprite bodySprite;
	Sprite armSprite;
	bool facingleft;
	bool hasmoved = false;
	bool directionchanged = false;
	textureDeclare texDec;

	objProjec mainProj;

	objTank()
	{
		bodySprite.setTexture(texDec.player1lefttexture);
		armSprite.setTexture(texDec.arm1texture);
	}

	void moveTank(bool left)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left)){
			x_pos += -1;
			bodySprite.setTexture(texDec.player1lefttexture);
			if (facingleft == false){
				directionchanged = true;
			}
			facingleft = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)){
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
		cout << angle << endl;
	}
};