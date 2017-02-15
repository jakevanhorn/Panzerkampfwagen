#include "objTank.h"

int main()
{
	srand(time(NULL));

	textureDeclare texDec;

	// Create the background
	RectangleShape background(Vector2f(1400, 800));
	background.setPosition(0, 0);
	background.setFillColor(Color(60, 60, 60));

	objTank tank[1]; // This is the vector that holds all of the players

	// Set basic info for our test player
	tank[0].x_pos = 40;
	tank[0].y_pos = 740;
	tank[0].bodySprite.setPosition(tank[0].x_pos,tank[0].y_pos);
	tank[0].bodySprite.setScale(1.0f, 1.0f);
	tank[0].facingleft = true;

	// Set basic values for our test projectile
	tank[0].mainProj.x_posC = tank[0].x_pos;
	tank[0].mainProj.y_posC = tank[0].y_pos;
	tank[0].mainProj.x_velocityC = 300;
	tank[0].mainProj.y_velocityC = 300 * -1;
	tank[0].mainProj.y_accelC = 200;
	tank[0].mainProj.projecReset(tank[0].x_pos, tank[0].y_pos);
	tank[0].mainProj.projectile.setScale(Vector2f(1, 1));

	RenderWindow window(VideoMode(1400, 800), "Panzerkampfwagen"); // Create the Window
	window.setFramerateLimit(60);

	while (window.isOpen()){ // Basic window code

		Event event1;
		while (window.pollEvent(event1))
		{
			if (event1.type == Event::Closed){
				window.close();
			}
		}

		window.clear(); // Clear window

		window.draw(background); // Draw basic window components
		
		for (int a = 0; a < 1; a++)
		{
			tank[a].bodySprite.setPosition(tank[a].x_pos, tank[a].y_pos);
			tank[a].armSprite.setOrigin(23, 3);
			tank[a].armSprite.setPosition(tank[a].x_pos + 14, tank[a].y_pos + 27);
			window.draw(tank[a].bodySprite);
			window.draw(tank[a].armSprite);
			window.draw(tank[a].mainProj.projectile);
		}

		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Space)){
			for (int a = 0; a < 1; a++)
			{
				if (tank[a].mainProj.testAir != 1) {
					tank[a].mainProj.projecReset(tank[0].x_pos, tank[0].y_pos);
					tank[a].mainProj.testAir = 1;
					tank[a].mainProj.clock.restart();
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) | Keyboard::isKeyPressed(Keyboard::Right)){
			tank[0].moveTank(true);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) | Keyboard::isKeyPressed(Keyboard::Down)){
			tank[0].moveArm();
		}

		for (int a = 0; a < 1; a++)
		{
			if (tank[a].mainProj.testAir == 0){
				tank[a].mainProj.projectile.setTexture(texDec.fireball);
				cout << "a";
			}

			if (tank[a].mainProj.testAir == 1){
				tank[a].mainProj.projectile.setTexture(texDec.fireball);
				tank[a].mainProj.time = tank[a].mainProj.clock.getElapsedTime();
				tank[a].mainProj.moveProj(tank[a].mainProj.time);
				tank[a].mainProj.clock.restart();

				cout << "b";
			}

			if (tank[a].mainProj.y_pos > 790){
				tank[a].mainProj.projecReset(tank[0].x_pos, tank[0].y_pos);
				tank[a].mainProj.testAir = 0;
			}
		}

	}
	return 10;
}