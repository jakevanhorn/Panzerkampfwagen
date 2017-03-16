#include "includeLibs.h" 
#include "textureDeclare.h"
#include "objTank.h"
#include "objProjec.h"

int checkPlayerTurn()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){ return 1; }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){ return 2; }
	else { return 0; }
}

int main()
{
	srand(time(NULL));

	textureDeclare texDec;

	int playerTurn = 0;
	int numTanks = 2;

	// Create the background
	sf::RectangleShape background(sf::Vector2f(1400, 800));
	background.setPosition(0, 0);
	background.setFillColor(sf::Color(60, 60, 60));

	std::vector <objTank> tanks;

	tanks.push_back(objTank(466, 400, &texDec));
	tanks.push_back(objTank(932, 740, &texDec));

	sf::RenderWindow window(sf::VideoMode(1400, 800), "Panzerkampfwagen"); // Create the Window
	window.setFramerateLimit(120);

	while (window.isOpen()){ // Basic window code

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}

		window.clear(); // Clear window

		// This is the section where we draw the sprite on the window

		window.draw(background); // Draw basic window components
		
		for (int a = 0; a < numTanks; a++)
		{
			window.draw(tanks[a].bodySprite);
			window.draw(tanks[a].armSprite);
			window.draw(tanks[a].mainProj[0].projectile);
		}

		window.display(); // Display the window

		// This is the section where all are functions are called if appropriate

		if (checkPlayerTurn() != 0){
			playerTurn = checkPlayerTurn() - 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) | sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			tanks[playerTurn].moveTank();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) | sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			tanks[playerTurn].moveArm();
		}

		tanks[playerTurn].changePos();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			tanks[playerTurn].mainProj[0].shootProj(tanks[playerTurn].x_pos, tanks[playerTurn].y_pos, tanks[playerTurn].angle, tanks[playerTurn].facingleft);
		}

		tanks[playerTurn].mainProj[0].moveProj();

		tanks[playerTurn].mainProj[0].testOut(tanks[playerTurn].x_pos, tanks[playerTurn].y_pos);

	}
	return 10;
}