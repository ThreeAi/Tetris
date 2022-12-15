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
				if(figure->checkLeft(d.getTileDisplay()))
					figure->left();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
			{
				if (figure->checkRight(d.getTileDisplay()))
					figure->right();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
			{
				figure->down();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
			{
				figure->up();
			}
		}
		if (figure->checkFall(d.getTileDisplay()))
		{
			figure->setFigure(d.getTileDisplay());
			delete figure;
			int r = rand() % 7 + 1;
			switch (r)
			{
			case 1:
			{
				figure = new FirstFigure();
				break;
			}
			case 2:
			{
				figure = new SecondFigure();
				break;
			}
			case 3:
			{
				figure = new ThirdFigure();
				break;
			}
			case 4:
			{
				figure = new FourthFigure();
				break;
			}
			case 5:
			{
				figure = new FifthFigure();
				break;
			}
			case 6:
			{
				figure = new SixthFigure();
				break;
			}
			case 7:
			{
				figure = new SeventhFigure();
				break;
			}
			}
		}
		vector<int> filledLines = d.filledLines();
		d.clearLines(filledLines);
		window.clear();
		d.draw(window);
		figure->draw(window);
		window.display();
	}
	return 0;
}
