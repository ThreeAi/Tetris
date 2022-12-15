#include "Display.h";

using namespace sf;

void Display::initialization()
{
	textDisplay.loadFromFile("images/tiles.png");
	spriteDisplay.setTexture(textDisplay);
}
void Display::draw(RenderWindow& window)
{
	for (int i = 0; i < HEIGHT_DISPLAY; i++)
		for (int j = 0; j < WIGTH_DISPLAY; j++)
		{
			char color = tileDisplay[i][j];
			switch (color)
			{
			case '0':
			{
				spriteDisplay.setTextureRect(IntRect(0, 0, LENGTH_TILE, LENGTH_TILE));
				spriteDisplay.setPosition(LENGTH_TILE * j, LENGTH_TILE * i);
				break;
			}
			case '1':
			{
				spriteDisplay.setTextureRect(IntRect(LENGTH_TILE * 1, 0, LENGTH_TILE, LENGTH_TILE));
				spriteDisplay.setPosition(LENGTH_TILE * j, LENGTH_TILE * i);
				break;
			}
			case '2':
			{
				spriteDisplay.setTextureRect(IntRect(LENGTH_TILE * 2, 0, LENGTH_TILE, LENGTH_TILE));
				spriteDisplay.setPosition(LENGTH_TILE * j, LENGTH_TILE * i);
				break;
			}
			case '3':
			{
				spriteDisplay.setTextureRect(IntRect(LENGTH_TILE * 3, 0, LENGTH_TILE, LENGTH_TILE));
				spriteDisplay.setPosition(LENGTH_TILE * j, LENGTH_TILE * i);
				break;
			}
			case '4':
			{
				spriteDisplay.setTextureRect(IntRect(LENGTH_TILE * 4, 0, LENGTH_TILE, LENGTH_TILE));
				spriteDisplay.setPosition(LENGTH_TILE * j, LENGTH_TILE * i);
				break;
			}
			case '5':
			{
				spriteDisplay.setTextureRect(IntRect(LENGTH_TILE * 5, 0, LENGTH_TILE, LENGTH_TILE));
				spriteDisplay.setPosition(LENGTH_TILE * j, LENGTH_TILE * i);
				break;
			}
			case '6':
			{
				spriteDisplay.setTextureRect(IntRect(LENGTH_TILE * 6, 0, LENGTH_TILE, LENGTH_TILE));
				spriteDisplay.setPosition(LENGTH_TILE * j, LENGTH_TILE * i);
				break;
			}
			case '7':
			{
				spriteDisplay.setTextureRect(IntRect(LENGTH_TILE * 7, 0, LENGTH_TILE, LENGTH_TILE));
				spriteDisplay.setPosition(LENGTH_TILE * j, LENGTH_TILE * i);
				break;
			}
			}
			window.draw(spriteDisplay);
		}
}
vector<int> Display::filledLines()
{
	vector<int> temp;
	for (int j = 0; j < HEIGHT_DISPLAY; j++)
	{
		int num = 0;
		for (int i = 0; i < WIGTH_DISPLAY; i++)
		{
			if (tileDisplay[j][i] == '0')
				num++;
		}
		if (num == 0)
			temp.push_back(j);
	}
	return temp;
}
void Display::clearLines(vector<int> temp)
{
	for (auto iter : temp)
	{
		tileDisplay.erase(tileDisplay.begin()+iter);
		tileDisplay.insert(tileDisplay.begin(), "0000000000");

	}
}
