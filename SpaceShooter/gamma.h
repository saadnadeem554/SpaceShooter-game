#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
//#include"invader.h"
#include <random>
using namespace std;

class Gamma: public Invader
{
	int gammaindex;
	Texture gammatex;
	Sprite gammasprite;
	int gammaxpos,gammaypos;
	Clock gammaclock;
	bool threshold;
	int randomtime;
	static int value;

public:


void updatevalue()
{
	if(value==10)
	{
		value = 2;
	}
	else
		value=value+2;
}



Gamma()
{
	srand(time(0));
	randomtime = value;
	updatevalue();
	gammaindex=0;
	threshold = false;
	gammaclock.restart();
}

void draw(int xpos, int ypos)
{
	std::string png_path = "img/gamma.png";
	gammatex.loadFromFile(png_path);
	gammasprite.setTexture(gammatex);
	gammasprite.setPosition(xpos,ypos);

}


Sprite returnsprite()
{
	return gammasprite;
}
int getrandval()
{
	return randomtime;
}
void urado(){delete this;}
void move(){}
void loadbomb(Bomb &b)
{


	if(!threshold)
	{
		if(randomtime != (int)gammaclock.getElapsedTime().asSeconds())
		{
			return;
		}
		else
		{
			threshold=true;
			gammaclock.restart();
		}
	}


if(((int)gammaclock.getElapsedTime().asSeconds())!=0 && ((int)gammaclock.getElapsedTime().asSeconds())%2==0)
{
	for(int i=0; i<gammaindex;i++)
	   	{
	   		if(bomb[i]->getactive()==false)
	   		{
	   			bomb[i] = &b;
	   		   	bomb[i]->drawbomb(gammasprite.getPosition().x+10, gammasprite.getPosition().y);
	   		 bomb[i]->setactive(true);
	   		 bombindex++;
				gammaclock.restart();
	   			return;
	   		}
	   	}

	bomb[gammaindex++] = &b;
	bomb[gammaindex-1]->setactive(true);
   	bomb[gammaindex-1]->drawbomb(gammasprite.getPosition().x+10, gammasprite.getPosition().y);
   	bombindex++;
	gammaclock.restart();
}
}

};

int Gamma::value=2;

