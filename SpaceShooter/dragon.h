#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>


using namespace std;
using namespace sf;



class Dragon: public Enemy
{
	Texture dragontex;
	Sprite dragonsprite;

public:
	Dragon(){}
	~Dragon(){}

	void draw(int xpos, int ypos)
	{
		std::string png_path = "img/dragon3.png";
		dragontex.loadFromFile(png_path);
		dragonsprite.setTexture(dragontex);
		dragonsprite.setPosition(xpos,ypos);

	}

	Sprite returnsprite()
	{
		return dragonsprite;
	}

	void urado(){delete this;}


	void loadbomb(Bomb &b)
	{
		cout<<bombindex<<endl;

			bomb[bombindex++] = &b;
			bomb[bombindex-1]->drawbomb(dragonsprite.getPosition().x + 25, dragonsprite.getPosition().y + 75,"img/tiltedright.png");
	}

	bool isColliding(Bullet &bullet)
	{return false;}

    void move()
    {

    }

    int getrandval(){return 1;}

};
