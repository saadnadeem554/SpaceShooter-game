
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;


class Fire: public Addon
{
	Texture firetex;
	Sprite firesprite;
	float speed;

public:
	Fire(){
		speed = 0.1;
	}

	void draw(int xpos, int ypos)
	{
		std::string png_path = "img/fire.png";
		firetex.loadFromFile(png_path);
		firesprite.setTexture(firetex);
		firesprite.setPosition(xpos,ypos);
	}

	void updateposition(int xpos, int yops)
	{
		firesprite.setPosition(xpos, yops);
	}

	void move()
	{
		firesprite.move(0, speed);
	}

	Sprite getsprite()
	{
		return firesprite;
	}

	string checkcollisionwithplayer(float ex,float ey,float ew,float eh)
		{
			float bx = firesprite.getPosition().x;
			float by = firesprite.getPosition().y;
			float bw = firesprite.getGlobalBounds().width;
			float bh = firesprite.getGlobalBounds().height;

			// Check if the bomb overlaps with the enemy's sprite
			if (bx + bw > ex && bx < ex + ew && by + bh > ey && by < ey + eh)
			{
				return "fire";
			}

			return "no";
		}

	~Fire()
	{
	}

};
