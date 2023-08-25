


#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;

class Life: public Addon
{
	Texture lifetex;
	Sprite lifesprite;
	float speed;

public:
	Life(){
		speed = 0.1;
	}

	void draw(int xpos, int ypos)
	{
		std::string png_path = "img/heart.png";
		lifetex.loadFromFile(png_path);
		lifesprite.setTexture(lifetex);
		lifesprite.setPosition(xpos,ypos);
	}

	void updateposition(int xpos, int yops)
	{
		lifesprite.setPosition(xpos, yops);
	}

	void move()
	{
		lifesprite.move(0, speed);
	}

	Sprite getsprite()
	{
		return lifesprite;
	}

	string checkcollisionwithplayer(float ex,float ey,float ew,float eh)
	{
		float bx = lifesprite.getPosition().x;
		float by = lifesprite.getPosition().y;
		float bw = lifesprite.getGlobalBounds().width;
		float bh = lifesprite.getGlobalBounds().height;


		// Check if the bomb overlaps with the enemy's sprite
		if (bx + bw > ex && bx < ex + ew && by + bh > ey && by < ey + eh)
		{
			return "life";
		}

		return "no";
	}

	~Life()
	{
	}
};
