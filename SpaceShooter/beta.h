#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>
#include <iostream>
using namespace std;

class Beta: public Invader
{
	int betaindex;
	Texture betatex;
	Sprite betasprite;
	int betaxpos,betaypos;
	Clock betaclock;
	bool threshold;
	int randomtime;
	static int value;

public:


void updatevalue()
{
	if(value==15)
	{
		value = 3;
	}
	else
		value=value+3;
}
int getrandval()
{
	return randomtime;
}
Beta()
{



	srand(time(0));
	randomtime = value;
	updatevalue();
	betaindex=0;
	betaclock.restart();
	threshold = false;
}

void draw(int xpos, int ypos)
{
	std::string png_path = "img/beta.png";
	betatex.loadFromFile(png_path);
	betasprite.setTexture(betatex);
	betasprite.setPosition(xpos,ypos);

}

Sprite returnsprite()
{
	return betasprite;
}

void urado(){delete this;}
void move(){}
void loadbomb(Bomb &b)
{


	if(!threshold)
		{
			if(randomtime != (int)betaclock.getElapsedTime().asSeconds())
			{
				return;
			}
			else
			{
				threshold=true;
				betaclock.restart();
			}
		}

if(((int)betaclock.getElapsedTime().asSeconds())!=0 && ((int)betaclock.getElapsedTime().asSeconds())%3==0)
{
	for(int i=0; i<betaindex;i++)
	   	{
	   		if(bomb[i]->getactive()==false)
	   		{
	   			bomb[i] = &b;
	   		   	bomb[i]->drawbomb(betasprite.getPosition().x+10, betasprite.getPosition().y);
	   		 bomb[i]->setactive(true);
	   		 bombindex++;
				betaclock.restart();
	   			return;
	   		}
	   	}
	bomb[betaindex++] = &b;
	bomb[betaindex-1]->setactive(true);

   	bomb[betaindex-1]->drawbomb(betasprite.getPosition().x+10, betasprite.getPosition().y);
   	bombindex++;
	betaclock.restart();
}
}

};

int Beta:: value = 3;
