#include "Figure.h"
#include "Parameters.h"

FirstFigure::FirstFigure()
{
	tiles = { {0, 0}, {1, 0} , { 2, 0 }, { 3, 0 }
};
	color = '2';
}
void FirstFigure::initialization()
{
	textTile.loadFromFile("images/tiles.png");
	spriteTile.setTexture(textTile);
	spriteTile.setTextureRect(IntRect(100, 0, 50, 50));
}
void Figure::draw(RenderWindow& window)
{
	for (auto iter = tiles.begin(); iter != tiles.end(); iter++)
	{
		spriteTile.setPosition(iter->x * LENGTH_TILE, iter->y * LENGTH_TILE);
		window.draw(spriteTile);
	}
}
void Figure::down()
{
	for (auto iter = tiles.begin(); iter != tiles.end(); iter++)
	{
		iter->y++;
	}
}
void Figure::left()
{
	for (auto iter = tiles.begin(); iter != tiles.end(); iter++)
	{
		iter->x--;
	}
}
void Figure::right()
{
	for (auto iter = tiles.begin(); iter != tiles.end(); iter++)
	{
		iter->x++;
	}
}
bool Figure::checkFall(String* tileDisplay)
{
	for (auto iter = tiles.begin(); iter != tiles.end(); iter++)
	{
		if (iter->y == 14 || tileDisplay[(iter->y)+1][iter->x] != '0')
			return true;
	}
	return false;
}
void Figure::setFigure(String* tileDisplay)
{
	for (auto iter = tiles.begin(); iter != tiles.end(); iter++)
	{
		tileDisplay[iter->y][iter->x] = color;
	}
}