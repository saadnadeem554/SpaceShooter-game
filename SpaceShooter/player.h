#include <SFML/Graphics.hpp>
#include<string.h>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;
class Player{
bool tilted;
Addon* addon;
string addontype;
string firedanger;
string changetimer;

int lives;
Texture shieldtex;
Sprite shieldsprite;

Texture firetex;
Sprite firesprite;

int bulletindex=0;
Texture tex;
Sprite sprite;
float speed=0.7;
int x,y;

SoundBuffer Buffer;
Sound lifeLostSound;

public:
Bullet* b[100];
Player(std::string png_path)
{
	lives = 3;
	Buffer.loadFromFile("poof.ogg");
	lifeLostSound.setBuffer(Buffer);
tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=340;y=700;
sprite.setPosition(x,y);
sprite.setScale(0.75,0.75);
tilted = false;

addontype = "";
addon = nullptr;
firedanger="";
changetimer="";

}


void setbulletindex(int a)
{
	bulletindex = a;
}

//----------------------correct the tilt--------------//
void correcttilt()
{
	if(tilted==true)
	{
		tex.loadFromFile("img/player_ship.png");
		sprite.setTexture(tex);
		tilted = false;

	}
}
//---------------------------move--------------//

void move(std::string s)
{
correcttilt();
float delta_x=0,delta_y=0;
if(s=="l")
	//move the player left
		delta_x=-1;
else if(s=="r")
	//move the player right
		delta_x=1;
if(s=="u")
{
	delta_y=-1;
}

else if(s=="d")
{
		delta_y=1;
}

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);

}
//------------------------Diagonal Movement------------//

void movediagonal(std::string s)
{
tilted = true;
float delta_x=0,delta_y=0;
		if(s=="dr")
		{
		tex.loadFromFile("img/playership_downright.png");
		sprite.setTexture(tex);
		delta_y=1;
		delta_x=1;
		}
		if(s=="ur")
		{
		tex.loadFromFile("img/playership_rightup.png");
		sprite.setTexture(tex);
		delta_y=-1;
		delta_x=1;
		}
		if(s=="dl")
		{
		tex.loadFromFile("img/playership_downleft.png");
		sprite.setTexture(tex);
		delta_y=1;
		delta_x=-1;
		}
		if(s=="ul")
		{
		tex.loadFromFile("img/playership_leftup.png");
		sprite.setTexture(tex);
		delta_y=-1;
		delta_x=-1;
		}

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);
}
//--------------wrap function---------------//
void wrap()
{
int delta_x=0,delta_y=0;
delta_x = sprite.getPosition().x;
delta_y = sprite.getPosition().y;
if(delta_x==780)
{
sprite.setPosition(-74, delta_y);
}
else if(delta_x==-74)
{
sprite.setPosition(780, delta_y);
}
if(delta_y==-90)
{
sprite.setPosition(delta_x, 780);
}
else if(delta_y==790)
{
sprite.setPosition(delta_x, -90);
}
}


//----------------------movingbullet--------------//
void movebullet()
{
	for(int i=0; i<100; i++)
	{
		if(b[i]->getactive()==true)
		b[i]->movebullet();
	}
}


//--------------destroybullet-----------------//

void destroybullet()
{


	for(int i=0; i<bulletindex; i++)
	{
		if(b[i]->checkend())
		{

/* 	if a bullet reaches the top it is deleted and remaining bullets
	are shifted one position back and index decremented by one*/

			delete b[i];
			if(bulletindex==1)
			{
				bulletindex--;
				return;
			}
			for(int j=i; j<bulletindex-1; j++)
			{
				b[j]=b[j+1];
			}
				bulletindex--;
		}
}
	return;

}

///////////////////////////////////////////////////////////

void makebullet(Bullet& bu, int index)
{


		b[index] = &bu;
		if(addontype=="fire")
		{
			b[index]->setfire("fire");
		}
		else
		{
			b[index]->setfire("");
		}
		b[index]->drawbullet(sprite.getPosition().x,sprite.getPosition().y);
		b[index]->setactive(true);


}
//-------------getter-----------//
int getbulletindex()
{
return bulletindex;
}

//--------------collision with bullet -------------//
bool checkcollisionwithbomb(Bomb &bomb)
{
	    if(addontype=="shield")
	    {
	    	return false;
	    }

		float bx = bomb.getsprite().getPosition().x;
		float by = bomb.getsprite().getPosition().y;
		float bw = bomb.getsprite().getGlobalBounds().width;
		float bh = bomb.getsprite().getGlobalBounds().height;
		float ex = sprite.getPosition().x;
		float ey = sprite.getPosition().y;
		float ew = sprite.getGlobalBounds().width;
		float eh = sprite.getGlobalBounds().height;

		// Check if the bomb overlaps with the enemy's sprite
		if (bx + bw > ex && bx < ex + ew && by + bh > ey && by < ey + eh)
		{
			return true;
		}

		return false;
}

//-------------update position after loss of life-------------------//
void updateplayer()
{
	sprite.setPosition(250, 700);
}


//------------------------------addon stuff----------------------//

Sprite getplayersprite()
{
	return sprite;
}


bool checkcollisionwithaddon(Addon* addon)
{
	float ex = sprite.getPosition().x;
	float ey = sprite.getPosition().y;
	float ew = sprite.getGlobalBounds().width;
	float eh = sprite.getGlobalBounds().height;
	string ret = addon->checkcollisionwithplayer(ex,ey,ew,eh);
	changetimer = addon->checkcollisionwithplayer(ex,ey,ew,eh);
	if(ret=="fire")
	{
		addontype = "fire";
		firedanger = "no";
		this->addon = addon;
		return true;

	}
	else if(ret=="danger")
	{
		firedanger = "danger";
		return true;

	}
	else if(ret=="shield")
	{
		addontype = "shield";
		firedanger = "no";
		this->addon = addon;
		return true;

	}
	else if(ret=="life")
	{
		firedanger = "life";
		return true;

	}

	return false;

}

void settype(string s)
{
	addontype = s;
}
string gettype() const
{
	return addontype;
}
string getfiredanger()const
{
	return changetimer;
}
Sprite getshield()
{
	return shieldsprite;
}
Sprite getfire()
{
	return firesprite;
}

void setfiredanger(string a)
{
	firedanger = a;
}

void updateshield()
{
	shieldsprite.setPosition(sprite.getPosition().x-30, sprite.getPosition().y-30);

}

void updatefire()
{
	firesprite.setPosition(sprite.getPosition().x-120, sprite.getPosition().y-80);

}



void implementaddon()
{
	if(firedanger == "life")
	{
		lives++;
	}
	else if(firedanger == "danger")
	{
		lifeLostSound.play();
		lives--;
		updateplayer();
	}

	if(addontype == "shield")
	{
		shieldtex.loadFromFile("img/shieldsprite.png");
		shieldsprite.setTexture(shieldtex);
		shieldsprite.setPosition(sprite.getPosition().x-30, sprite.getPosition().y-30);
	}
	else if(addontype == "fire")
	{
		firetex.loadFromFile("img/supersayn.png");
		firesprite.setTexture(firetex);
		firesprite.setPosition(sprite.getPosition().x-120, sprite.getPosition().y-80);

	}

	cout<<lives<<endl;
}

void decrementlives()
{
	lifeLostSound.play();
	lives--;
}
int getlives()
{
	return lives;
}

bool checkcollisionwithenemy(Enemy* enemy)
{
	 if(addontype=="shield")
	{
		return false;
	}

	float bx = enemy->returnsprite().getPosition().x;
	float by = enemy->returnsprite().getPosition().y;
	float bw = enemy->returnsprite().getGlobalBounds().width;
	float bh = enemy->returnsprite().getGlobalBounds().height;


	float ex = sprite.getPosition().x;
	float ey = sprite.getPosition().y;
	float ew = sprite.getGlobalBounds().width;
	float eh = sprite.getGlobalBounds().height;

	// Check if the bomb overlaps with the enemy's sprite
	if (bx + bw > ex && bx < ex + ew && by + bh > ey && by < ey + eh)
	{
		return true;
	}

	return false;
}

};
