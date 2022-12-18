#include <iostream>
#include "Display.h"
#include "Figure.h"

using namespace sf;
using namespace std;

int main()
{
	Font font;
	font.loadFromFile("GULAG Pavljenko.otf");
	Text text("", font, 70);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	RenderWindow window(VideoMode(LENGTH_TILE * WIGTH_DISPLAY, LENGTH_TILE * HEIGHT_DISPLAY), "Tetris");
	text.setPosition(window.getView().getCenter().x - 200, window.getView().getCenter().y - 75);
	Display d = Display();
	d.initialization();
	float fall = 0;
	int score = 0;
	Clock clock;
	Figure* figure = new FirstFigure();
	bool flag = true;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		if (time / 1000000 > 1)
		{
			figure->down();
			clock.restart();
		}
		Vector2i pixelPos = Mouse::getPosition(window);
		Event event;
		if (d.checkEndGame())
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
				{
					if (figure->checkLeft(d.getTileDisplay()))
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
					if (figure->checkUp(d.getTileDisplay()))
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
			score += filledLines.size();
			d.clearLines(filledLines);
			window.clear();
			d.draw(window);
			figure->draw(window);
			window.display();
		}
		else
		{
			window.clear();
			d.draw(window);
			string str = to_string(score*100);
			text.setString("game over \n score : " + str);
			window.draw(text);
			window.display();
		}
	}
	return 0;
}
