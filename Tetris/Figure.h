#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

class Figure
{
protected:
	struct Point
	{
		int x;
		int y;
	};
	vector<Point> tiles;
	Texture textTile;
	Sprite spriteTile;
public:
	//virtual void initialization();
	void draw(RenderWindow& window);
	void left();
	void right();
	void down();
};
class FirstFigure : public Figure
{
public:
	FirstFigure();
	void initialization();
};
