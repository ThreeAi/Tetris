#include <iostream>
#include "Display.h"

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(LENGTH_TILE * WIGTH_DISPLAY, LENGTH_TILE * HEIGHT_DISPLAY), "Tetris");
	Display d = Display();
	d.initialization();
	while (window.isOpen())
	{
		Vector2i pixelPos = Mouse::getPosition(window);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			//if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left)//если нажата клавиша мыши			

		}
		window.clear();
		d.draw(window);	
		window.display();
	}
	return 0;
}
