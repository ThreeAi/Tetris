#include <iostream>
#include "Display.h"
#include "Figure.h"

using namespace sf;
using namespace std;

void setFigure(String* tiles, Figure& figure);
int main()
{
	RenderWindow window(VideoMode(LENGTH_TILE * WIGTH_DISPLAY, LENGTH_TILE * HEIGHT_DISPLAY), "Tetris");
	Display d = Display();
	d.initialization();
	float fall = 0;
	Clock clock;
	FirstFigure* f1 = new FirstFigure();
	f1->initialization();
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		fall += time;
		if (fall > 1500)
		{
			f1->down();
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
				f1->left();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
			{
				f1->right();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
			{
				f1->down();
			}
		}
		if (f1->fallDown())
		{
			setFigure(d.getTileDisplay(), *f1);
			delete f1;
			f1 = new FirstFigure();
			f1->initialization();
		}
		window.clear();
		d.draw(window);
		f1->draw(window);
		window.display();
	}
	return 0;
}
void setFigure(String* tiles, Figure& figure)
{
	auto tile = figure.getTiles();
	char c = figure.getColor();
	for (auto iter = tile.begin(); iter != tile.end(); iter++)
	{
		tiles[iter->y][iter->x] = c;
	}
}
