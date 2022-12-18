#include "Figure.h"
#include "Parameters.h"

FirstFigure::FirstFigure()
{
	tiles = {															// _ _
		{ { 4, 0 }, { 5, 0 } , { 4, 1 }, { 5, 1 } },					//|_|_|
		{ { 4, 0 }, { 5, 0 } , { 4, 1 }, { 5, 1 } },					//|_|_|
		{ { 4, 0 }, { 5, 0 } , { 4, 1 }, { 5, 1 } },
		{ { 4, 0 }, { 5, 0 } , { 4, 1 }, { 5, 1 } }
	};
	position = 0;
	color = '1';
	textTile.loadFromFile("images/tiles.png");
	spriteTile.setTexture(textTile);
	spriteTile.setTextureRect(IntRect(LENGTH_TILE * 1, 0, LENGTH_TILE, LENGTH_TILE));
}
SecondFigure::SecondFigure()
{
	tiles = {
		{ { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 } },						// _ _ _ _
		{ { 4, -1 }, { 4, 0 }, { 4, 1 }, { 4, 2 } },					//|_|_|_|_|
		{ { 3, 1 }, { 4, 1 }, { 5, 1 }, { 6, 1 } },
		{ { 5, -1 }, { 5, 0 }, { 5, 1 }, { 5, 2 } },
};
	position = 0;
	color = '2';
	textTile.loadFromFile("images/tiles.png");
	spriteTile.setTexture(textTile);
	spriteTile.setTextureRect(IntRect(LENGTH_TILE * 2, 0, LENGTH_TILE, LENGTH_TILE));
}
ThirdFigure::ThirdFigure()
{
	tiles = {
		{ { 3, 0 }, { 4, 0 }, { 5, 0 }, { 5, 1 } },						// _ _ _
		{ { 4, -1 }, { 5, -1 }, { 4, 0 }, { 4, 1 } },					//|_|_|_|
		{ { 4, -1 }, { 4, 0 }, { 5, 0 }, { 6, 0 } },					//    |_|
		{ { 4, 0 }, { 5, 0 }, { 5, -1 }, { 5, -2 } },
	};
	position = 0;
	color = '3';
	textTile.loadFromFile("images/tiles.png");
	spriteTile.setTexture(textTile);
	spriteTile.setTextureRect(IntRect(LENGTH_TILE * 3, 0, LENGTH_TILE, LENGTH_TILE));
}
FourthFigure::FourthFigure()
{
	tiles = {
		{ { 4, 0 }, { 5, 0 }, { 6, 0 }, { 4, 1 } },						// _
		{ { 4, 0 }, { 5, 0 }, { 4, -1 }, { 4, -2 } },					//|_|_ _
		{ { 3, 0 }, { 4, 0 }, { 5, 0 }, { 5, -1 } },					//|_|_|_|
		{ { 4, 0 }, { 5, 0 }, { 5, 1 }, { 5, 2 } },
	};
	position = 0;
	color = '4';
	textTile.loadFromFile("images/tiles.png");
	spriteTile.setTexture(textTile);
	spriteTile.setTextureRect(IntRect(LENGTH_TILE * 4, 0, LENGTH_TILE, LENGTH_TILE));
}
FifthFigure::FifthFigure()
{
	tiles = {
		{ { 3, 0 }, { 4, 0 }, { 4, 1 }, { 5, 1 } },						// _ _
		{ { 4, 1 }, { 4, 0 }, { 5, 0 }, { 5, -1 } },					//|_|_|_
		{ { 3, 0 }, { 4, 0 }, { 4, 1 }, { 5, 1 } },						//  |_|_|
		{ { 4, 1 }, { 4, 0 }, { 5, 0 }, { 5, -1 } },
	};
	position = 0;
	color = '5';
	textTile.loadFromFile("images/tiles.png");
	spriteTile.setTexture(textTile);
	spriteTile.setTextureRect(IntRect(LENGTH_TILE * 5, 0, LENGTH_TILE, LENGTH_TILE));
}
SixthFigure::SixthFigure()
{
	tiles = {
		{ { 3, 1 }, { 4, 0 }, { 4, 1 }, { 5, 0 } },						//   _ _ 
		{ { 5, 1 }, { 4, 0 }, { 5, 0 }, { 4, -1 } },					// _|_|_|
		{ { 3, 1 }, { 4, 0 }, { 4, 1 }, { 5, 0 } },						//|_|_|
		{ { 5, 1 }, { 4, 0 }, { 5, 0 }, { 4, -1 } },
	};
	position = 0;
	color = '6';
	textTile.loadFromFile("images/tiles.png");
	spriteTile.setTexture(textTile);
	spriteTile.setTextureRect(IntRect(LENGTH_TILE * 6, 0, LENGTH_TILE, LENGTH_TILE));
}
SeventhFigure::SeventhFigure()
{
	tiles = {
		{ { 3, 0 }, { 4, 0 }, { 5, 0 }, { 4, 1 } },						// _ _ _ 
		{ { 4, -1 }, { 4, 0 }, { 4, 1 }, { 5, 0 } },					//|_|_|_|
		{ { 3, 0 }, { 4, 0 }, { 5, 0 }, { 4, -1 } },					//  |_|
		{ { 4, -1 }, { 4, 0 }, { 4, 1 }, { 3, 0 } },
	};
	position = 0;
	color = '7';
	textTile.loadFromFile("images/tiles.png");
	spriteTile.setTexture(textTile);
	spriteTile.setTextureRect(IntRect(LENGTH_TILE * 7, 0, LENGTH_TILE, LENGTH_TILE));
}
void Figure::draw(RenderWindow& window)
{
	for (auto iter = tiles[position].begin(); iter != tiles[position].end(); iter++)
	{
		spriteTile.setPosition(iter->x * LENGTH_TILE, iter->y * LENGTH_TILE);
		window.draw(spriteTile);
	}
}
void Figure::down()
{
	for(int i = 0; i <= 3; i++)
		for (auto iter = tiles[i].begin(); iter != tiles[i].end(); iter++)
		{
		iter->y++;
		}
}
bool Figure::checkLeft(vector<String>* tileDisplay)
{
	for (auto iter = tiles[position].begin(); iter != tiles[position].end(); iter++)
	{
		if (iter->x == 0)
			return false;
		if((*tileDisplay)[iter->y][(iter->x) - 1] != '0')
			return false;
	}
	return true;
}
void Figure::left()
{
	for (int i = 0; i <= 3; i++)
		for (auto iter = tiles[i].begin(); iter != tiles[i].end(); iter++)
		{
			iter->x--;
		}
}
bool Figure::checkRight(vector<String>* tileDisplay)
{
	for (auto iter = tiles[position].begin(); iter != tiles[position].end(); iter++)
	{
		if (iter->x == WIGTH_DISPLAY - 1)
			return false;
		if ((*tileDisplay)[iter->y][(iter->x) + 1] != '0')
			return false;
	}
	return true;
}
void Figure::right()
{
	for (int i = 0; i <= 3; i++)
		for (auto iter = tiles[i].begin(); iter != tiles[i].end(); iter++)
		{
			iter->x++;
		}
}
bool Figure::checkUp(vector<String>* tileDisplay)
{
	for (auto iter = tiles[(position + 1) % 4].begin(); iter != tiles[(position + 1) % 4].end(); iter++)
	{
		if (iter->y < 0 || iter->x < 0 || iter->x > HEIGHT_DISPLAY - 1)
			return false;
		if ((*tileDisplay)[iter->y][(iter->x)] != '0')
			return false;
	}
	return true;
}
void Figure::up()
{
	position++;
	position = position % 4;
}
bool Figure::checkFall(vector<String>* tileDisplay)
{
	for (auto iter = tiles[position].begin(); iter != tiles[position].end(); iter++)
	{
		if (iter->y == HEIGHT_DISPLAY-1 || (*tileDisplay)[(iter->y)+1][iter->x] != '0')
			return true;
	}
	return false;
}
void Figure::setFigure(vector<String>* tileDisplay)
{
	for (auto iter = tiles[position].begin(); iter != tiles[position].end(); iter++)
	{
		(*tileDisplay)[iter->y][iter->x] = color;
	}
}
