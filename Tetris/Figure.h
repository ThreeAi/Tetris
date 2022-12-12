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
	char color;
public:
	vector<Point> getTiles() { return tiles; }
	char getColor() { return color; }
	void draw(RenderWindow& window);
	void left();
	void right();
	void down();
	bool checkFall(vector<String>* tileDisplay);
	void setFigure(vector<String>* tileDisplay);
	bool checkLeft();
	bool checkRight();
};
class FirstFigure : public Figure
{
public:
	FirstFigure();
};
class SecondFigure : public Figure
{
public:
	SecondFigure();
};
