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
	FirstFigure* f1gure = new FirstFigure();
	f1gure->initialization();
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		fall += time;
		cout << time << " " << fall << endl;
		if (fall > 1500)
		{
			f1gure->down();
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
				f1gure->left();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
			{
				f1gure->right();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
			{
				f1gure->down();
			}
		}
		if (f1gure->checkFall(d.getTileDisplay()))
		{
			f1gure->setFigure(d.getTileDisplay());
			delete f1gure;
			f1gure = new FirstFigure();
			f1gure->initialization();
		}
		//if (d.checkLowerLine())
		//{
		//	d.clearLowerLine();
		//}
		window.clear();
		d.draw(window);
		f1gure->draw(window);
		window.display();
	}
	return 0;
}
