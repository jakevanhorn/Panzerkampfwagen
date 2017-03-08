//#ifndef textureDeclare_HEADER
//#define textureDeclare_HEADER
#pragma once

#include "includeLibs.h"

class textureDeclare
{
public:

	std::map <std::string, sf::Texture> textures;

	textureDeclare(){

		addTexture("RedLeft", "Wizard_Red_Left.png");
		addTexture("RedRight","Wizard_Red_Right.png");
		addTexture("BlueLeft","Wizard_Blue_Left.png");
		addTexture("BlueRight","Wizard_Blue_Right.png");
		addTexture("RedArm","Wizard_Red_Arm.png");
		addTexture("BlueArm","Wizard_Blue_Arm.png");
		addTexture("Fireball","fireBall.png");
		addTexture("Hidden","Hidden.png");

		//if (!textures[0].loadFromFile("Wizard_Red_Left.png")){} / Example code if you need to debug the textures being loaded
	}

	void addTexture(std::string name, std::string filename)
	{
		sf::Texture tempTexture;
		if (!tempTexture.loadFromFile(filename)){ std::cout << "Error"; }

		textures[name] = tempTexture;
	}

	//sf::Texture* getTextureByName(std::string name)
	//{
	//	return &textures[name];
	//}

};

//#endif