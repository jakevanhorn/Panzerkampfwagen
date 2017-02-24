#include "objTank.h"

int checkPlayerTurn()
{
	if (Keyboard::isKeyPressed(Keyboard::Num1)){ return 1; }
	else if (Keyboard::isKeyPressed(Keyboard::Num2)){ return 2; }
	else { return 0; }
}

int main()
{
	srand(time(NULL));

	textureDeclare texDec;

	int playerTurn = 0;

	// Create the background
	RectangleShape background(Vector2f(1400, 800));
	background.setPosition(0, 0);
	background.setFillColor(Color(60, 60, 60));

	vector <objTank> tanks;

	objTank testTank(466, 740);

	//tanks.push_back(testTank);
	//testTank.x_pos = 932;
	//testTank.changePos();
	//tanks.push_back(testTank);

	//tanks.push_back(objTank(466, 740));
	tanks.push_back(objTank(100, 740));
	tanks.push_back(objTank(932, 740));

	RenderWindow window(VideoMode(1400, 800), "Panzerkampfwagen"); // Create the Window
	window.setFramerateLimit(120);

	while (window.isOpen()){ // Basic window code

		Event event1;
		while (window.pollEvent(event1))
		{
			if (event1.type == Event::Closed){
				window.close();
			}
		}

		window.clear(); // Clear window

		// This is the section where we draw the sprite on the window

		window.draw(background); // Draw basic window components
		
		for (int a = 0; a < 2; a++)
		{
			window.draw(tanks[a].bodySprite);
			window.draw(tanks[a].armSprite);
			window.draw(tanks[a].testProj.projectile);
		}

		window.display(); // Display the window

		// This is the section where all are functions are called if appropriate

		if (checkPlayerTurn() != 0){
			playerTurn = checkPlayerTurn() - 1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) | Keyboard::isKeyPressed(Keyboard::Right)){
			tanks[playerTurn].moveTank();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) | Keyboard::isKeyPressed(Keyboard::Down)){
			tanks[playerTurn].moveArm();
		}

		tanks[playerTurn].changePos();

		if (Keyboard::isKeyPressed(Keyboard::Space)){
			tanks[playerTurn].testProj.shootProj(tanks[playerTurn].x_pos, tanks[playerTurn].y_pos);
		}

		tanks[playerTurn].testProj.moveProj();

		tanks[playerTurn].testProj.testOut(tanks[playerTurn].x_pos, tanks[playerTurn].y_pos);



	}
	return 10;
}