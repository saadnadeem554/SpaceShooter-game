

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;


class Danger: public Addon
{
	Texture dangertex;
	Sprite dangersprite;
	float speed;

public:
	Danger(){
		speed = 0.1;
	}

	void draw(int xpos, int ypos)
	{
		std::string png_path = "img/danger.png";
		dangertex.loadFromFile(png_path);
		dangersprite.setTexture(dangertex);
		dangersprite.setPosition(xpos,ypos);
	}

	void updateposition(int xpos, int yops)
	{
		dangersprite.setPosition(xpos, yops);
	}

	void move()
	{
		dangersprite.move(0, speed);
	}

	Sprite getsprite()
	{
		return dangersprite;
	}

	string checkcollisionwithplayer(float ex,float ey,float ew,float eh)
	{
		float bx = dangersprite.getPosition().x;
		float by = dangersprite.getPosition().y;
		float bw = dangersprite.getGlobalBounds().width;
		float bh = dangersprite.getGlobalBounds().height;

		// Check if the bomb overlaps with the enemy's sprite
		if (bx + bw > ex && bx < ex + ew && by + bh > ey && by < ey + eh)
		{
			return "danger";
		}

		return "no";
	}


~Danger()
{
}
};

