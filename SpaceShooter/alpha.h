#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace sf;

class Alpha: public Invader
{

int alphaindex;
Texture alphatex;
Sprite alphasprite;
int alphaxpos,alphaypos;
Clock alphaclock;
int randomtime;
bool threshold;
static int value;


public:


void updatevalue()
{

	if(value==11)
		{
			value = 1;
		}
		else
		value=value+2;
}

int getrandval()
{
	return randomtime;
}

Alpha()
{
	alphaindex=0;
	srand(time(0));
	randomtime = value;
	updatevalue();
	alphaclock.restart();
	threshold = false;
}

void draw(int xpos, int ypos)
{
	std::string png_path = "img/alpha.png";
	alphatex.loadFromFile(png_path);
	alphasprite.setTexture(alphatex);
	alphasprite.setPosition(xpos,ypos);


}

Sprite returnsprite()
{
	return alphasprite;
}
void urado(){delete this;}
void move(){}
void loadbomb(Bomb &b)
{

	if(!threshold)
	{
		if(randomtime != (int)alphaclock.getElapsedTime().asSeconds())
		{
			return;
		}
		else
		{
			threshold=true;
			alphaclock.restart();
		}
	}

if(((int)alphaclock.getElapsedTime().asSeconds())!=0 && ((int)alphaclock.getElapsedTime().asSeconds())%5==0)
{

	for(int i=0; i<alphaindex;i++)
   	{
   		if(bomb[i]->getactive()==false)
   		{
   			bomb[i] = &b;
   		   	bomb[i]->drawbomb(alphasprite.getPosition().x+10, alphasprite.getPosition().y);
   		   	bomb[i]->setactive(true);
   		   	bombindex++;
			alphaclock.restart();
   			return;
   		}
   	}

	bomb[alphaindex++] = &b;
	bomb[alphaindex-1]->setactive(true);

   	bomb[alphaindex-1]->drawbomb(alphasprite.getPosition().x+10, alphasprite.getPosition().y);
   	bombindex++;
	alphaclock.restart();
}
}

~Alpha(){}
};

int Alpha:: value = 1;


