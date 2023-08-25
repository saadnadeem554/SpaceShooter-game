#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;

class Bomb{
Texture bombtex;
Sprite bombsprite;
float speed;
bool active;

public:
Bomb()
{
	speed = 0.1;
	active = false;

}

void setactive(bool a)
{
	active = a;
}
bool getactive()const
{
	return active;
}
void drawbomb(float x, float y, string png = "img/bomb.png" )
{


	bombtex.loadFromFile(png);
	bombsprite.setTexture(bombtex);
	bombsprite.setPosition(x,y);

}
Sprite getsprite()
{

	return bombsprite;
}
void movebomb()
{

    bombsprite.move(0, speed);
}
bool checkend()
{
	int ypos = bombsprite.getPosition().y;

		if(ypos==750)
		{
			return true;
		}

		else
			return false;
}

void updateposition(float x, float y)
{
	bombsprite.setPosition(x, y);
}

void updatebombspeed(int level)
{
	if(level==1)
	{
		speed = 0.1;
	}
	else if(level ==2)
	{
		speed = 0.5;
	}
	else if(level ==3)
	{
		speed = 0.7;
	}
}

};
