#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include"enemy.h"


using namespace std;
using namespace sf;



class Monster: public Enemy
{
	Texture monstertex;
	Sprite monstersprite;
	bool change;
	float speed;

public:
	Monster()
	{
		change = false;
		speed = 0.1;
	}

	void draw(int xpos, int ypos)
	{
		std::string png_path = "img/m.png";
		monstertex.loadFromFile(png_path);
		monstersprite.setTexture(monstertex);
		monstersprite.setPosition(xpos,ypos);

	}

	Sprite returnsprite()
	{
		return monstersprite;
	}

	void urado(){delete this;}


	void loadbomb(Bomb &b)
	{
			bomb[bombindex++] = &b;
			bomb[bombindex-1]->drawbomb(monstersprite.getPosition().x, monstersprite.getPosition().y,"img/p.png");
	}

	bool isColliding(Bullet &bullet)
	{return false;}

    void move()
    {
    	float xpos = monstersprite.getPosition().x;
    	float ypos = monstersprite.getPosition().y;

    	if(ypos < 250)
    	{
    		monstersprite.move(0, 0.5);
    	}

    	if(xpos >= 680)
    		change = true;

    	if( xpos != 680 && ypos >= 250 && (change==false))
    	{
    		monstersprite.move(speed, 0);
    	}

    	if(xpos != 0 && change && ypos >= 250)
    	{
    		monstersprite.move(-speed, 0);
    	}

    	if(xpos <= 0)
    	    change = false;
    }

int getrandval(){return 1;}
virtual void updatespeed(int level)
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
