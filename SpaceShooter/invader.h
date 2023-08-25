#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;


class Invader: public Enemy
{


public:
bool isColliding(Bullet &bullet)
{
	float bx = bullet.getsprite().getPosition().x;
	float by = bullet.getsprite().getPosition().y;
	float bw = bullet.getsprite().getGlobalBounds().width;
	float bh = bullet.getsprite().getGlobalBounds().height;

	float ex = this->returnsprite().getPosition().x;
	float ey = this->returnsprite().getPosition().y;
	float ew = this->returnsprite().getGlobalBounds().width;
	float eh = this->returnsprite().getGlobalBounds().height;

	// Check if the bullet overlaps with the enemy's sprite
	if (bx + bw >= ex && bx <= ex + ew && by + bh >= ey && by <= ey + eh)
	{
		return true;
	}

	return false;
}

~Invader(){}
};
