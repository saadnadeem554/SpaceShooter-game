#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
//#include "bomb.h"
using namespace std;

class Enemy
{
public:
	Bomb* bomb[200];
	int bombindex=0;
    virtual void draw(int xpos, int ypos) = 0;
    virtual Sprite returnsprite()=0;
    virtual bool isColliding(Bullet &bullet)=0;
    virtual void urado()=0;
    virtual void loadbomb(Bomb& b)=0;
    virtual void move()=0;
    virtual int getrandval()=0;

    virtual void updatespeed(int){}
    virtual ~Enemy() = 0;
};
Enemy::~Enemy(){}
