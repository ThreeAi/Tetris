#include <iostream>
#include <SFML\Graphics.hpp>
#include "Parameters.h"
#include <vector>

using namespace sf;
using namespace std;

class Display
{
private: 
	vector <String> tileDisplay = {
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000"
	};
	Texture textDisplay;
	Sprite spriteDisplay;
public:
	bool checkEndGame();
	vector<String>* getTileDisplay() { return &tileDisplay; }
	void initialization();
	void draw(RenderWindow& window);
	vector<int> filledLines();
	void clearLines(vector<int> temp);
};
