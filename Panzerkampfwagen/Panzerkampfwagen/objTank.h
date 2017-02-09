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
	textureDeclare texDec;

	objProjec mainProj;

	objTank()
	{
		bodySprite.setTexture(texDec.player1lefttexture);
	}

	void moveTank(bool left)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left)){
			x_pos += -1.5;
			bodySprite.setTexture(texDec.player1lefttexture);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)){
			x_pos += 1.5;
			bodySprite.setTexture(texDec.player1righttexture);
		}
	}

};