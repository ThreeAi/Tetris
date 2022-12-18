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
	vector<vector<Point>> tiles;
	Texture textTile;
	Sprite spriteTile;
	char color;
	int position;
public:
	vector<vector<Point>> getTiles() { return tiles; }
	char getColor() { return color; }
	void draw(RenderWindow& window);
	void left();
	bool checkLeft(vector<String>* tileDisplay);
	void right();
	bool checkRight(vector<String>* tileDisplay);
	void down();
	void up();
	bool checkUp(vector<String>* tileDisplay);
	bool checkFall(vector<String>* tileDisplay);
	void setFigure(vector<String>* tileDisplay);
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
class ThirdFigure : public Figure
{
public:
	ThirdFigure();
};
class FourthFigure : public Figure
{
public:
	FourthFigure();
};
class FifthFigure : public Figure
{
public:
	FifthFigure();
};
class SixthFigure : public Figure
{
public:
	SixthFigure();
};
class SeventhFigure : public Figure
{
public:
	SeventhFigure();
};