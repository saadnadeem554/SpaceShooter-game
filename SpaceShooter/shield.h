
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;

class Shield: public Addon
{
	Texture shieldtex;
	Sprite shieldsprite;
	float speed;

public:
	Shield(){
		speed = 0.1;
	}

	void draw(int xpos, int ypos)
	{
		std::string png_path = "img/shield.png";
		shieldtex.loadFromFile(png_path);
		shieldsprite.setTexture(shieldtex);
		shieldsprite.setPosition(xpos,ypos);
	}

	void updateposition(int xpos, int yops)
	{
		shieldsprite.setPosition(xpos, yops);
	}

	void move()
	{
		shieldsprite.move(0, speed);
	}

	Sprite getsprite()
	{
		return shieldsprite;
	}

	string checkcollisionwithplayer(float ex,float ey,float ew,float eh)
			{
				float bx = shieldsprite.getPosition().x;
				float by = shieldsprite.getPosition().y;
				float bw = shieldsprite.getGlobalBounds().width;
				float bh = shieldsprite.getGlobalBounds().height;

				// Check if the bomb overlaps with the enemy's sprite
				if (bx + bw > ex && bx < ex + ew && by + bh > ey && by < ey + eh)
				{

					return "shield";
				}

				return "no";
			}

	~Shield()
	{
	}
};



