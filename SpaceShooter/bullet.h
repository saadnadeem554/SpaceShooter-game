#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;

class Bullet
{
	bool active;
	Texture btex;
	Sprite bsprite;
	float bspeed=1.5;
	string fire;

public:


Bullet()
{
	active = false;
	fire = "";

}
void setfire(string a)
{
	fire = a;
}
string getfire()
{
	return fire;
}
Sprite getsprite()
{
	return bsprite;
}

//----------setter getter for active status-----//
void setactive(bool a)
{
	active = a;
}
bool getactive()const
{
	return active;
}




void movebullet()
{

bsprite.move(0, -bspeed);

}

bool checkend()
{
	int ypos = bsprite.getPosition().y;

	if(ypos==0)
	{
		return true;
	}

	else
		return false;
}
void drawbullet(float x, float y)
{
std::string png_path="img/laserBlue01.png";
if(fire=="fire")
{
	png_path = "img/firelaser.png";
}

btex.loadFromFile(png_path);
bsprite.setTexture(btex);
bsprite.setPosition(x+35,y);
}
};
