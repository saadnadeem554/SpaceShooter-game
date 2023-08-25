

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;



class Addon
{


public:
 virtual void draw(int xpos, int yops)=0;
 virtual void updateposition(int xpos, int yops)=0;
 virtual void move()=0;
 virtual Sprite getsprite()=0;
 virtual string checkcollisionwithplayer(float, float,float,float) = 0;

virtual ~Addon()
{
}

};



