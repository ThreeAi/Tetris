#include <SFML\Graphics.hpp>
#include "Parameters.h"
using namespace sf;

class Display
{
private: 
	String tileDisplay[HEIGHT_DISPLAY] = { 
		"0000000000",
		"0001111000",
		"0000000000",
		"0000002000",
		"0000222000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
	};
	Texture textDisplay;
	Sprite spriteDisplay;
public:
	void initialization();
	void draw(RenderWindow& window);
};
