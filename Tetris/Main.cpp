#include <iostream>
#include "Display.h"
#include "Figure.h"

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(LENGTH_TILE * WIGTH_DISPLAY, LENGTH_TILE * HEIGHT_DISPLAY), "Tetris");
	Display d = Display();
	d.initialization();
	float fall = 0;
	Clock clock;
	Figure* figure = new FirstFigure();
	bool flag = true;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		fall += time;
		cout << time << " " << fall << endl;
		if (fall > 1500)
		{
			figure->down();
			fall = 0;
		}
		Vector2i pixelPos = Mouse::getPosition(window);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
			{
				if(figure->checkLeft())
					figure->left();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
			{
				if (figure->checkRight())
					figure->right();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
			{
				figure->down();
			}
		}
		if (figure->checkFall(d.getTileDisplay()))
		{
			figure->setFigure(d.getTileDisplay());
			delete figure;
			if (flag)
				figure = new SecondFigure();
			else
				figure = new FirstFigure();
			flag = !flag;
		}
		if (d.fillLowerLine())
		{
			d.clearLowerLine();
		}
		window.clear();
		d.draw(window);
		figure->draw(window);
		window.display();
	}
	return 0;
}
