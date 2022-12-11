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
	FirstFigure f1 = FirstFigure();
	f1.initialization();
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		cout << time << endl;
		fall += time;
		if (fall > 2500)
		{
			f1.down();
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
				f1.left();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
			{
				f1.right();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
			{
				f1.down();
			}
		}
		window.clear();
		d.draw(window);
		f1.draw(window);
		window.display();
	}
	return 0;
}
