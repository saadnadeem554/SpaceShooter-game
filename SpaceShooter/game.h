
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "bullet.h"
#include "bomb.h"
#include "addon.h"
#include "life.h"
#include "danger.h"
#include "fire.h"
#include "shield.h"
#include"monster.h"
#include"dragon.h"
#include"invader.h"
#include "alpha.h"
#include "beta.h"
#include "gamma.h"
#include "player.h"
#include <sstream>
#include <fstream>
#include <time.h>
#include "menu.h"



const char title[] = "OOP-Project, Spring-2023";
using namespace sf;
class Game
{

	Menu* menu;


int score;
float xdrag;


string pause;
string playername;

int no_alpha;
int alphacount;

int no_beta;
int betacount;
int no_gamma;
int gammacount;
int level;
int phase;


int monstertimetocome;
Enemy* monster;
bool ismonsteractive;
bool monsterfire;
bool cooldown;

string turn;
Enemy* dragon;
bool isdragonactive;
int dragontimetocome;


Addon* addon[4];
bool addonactive;
Sprite background; //Game background sprite
Texture bg_texture;
Player* p; //player
// add other game attributes
Enemy* alpha[20];
Enemy* beta[20];
Enemy* gamma[20];
Bomb* bomb1[100];
int bombindex;
Bullet* b[100];
int bulletindex=0;


public:


Game()
{
	srand(time(0));

xdrag=0;

pause="";
playername = "";

menu = new Menu;

p=new Player("img/player_ship.png");
bg_texture.loadFromFile("img/background.png");
background.setTexture(bg_texture);
background.setScale(2.3, 1.2);


level =1;
phase = 1;
no_alpha=0;
no_beta=0;
no_gamma=0;
bombindex=100;
alphacount=0;
betacount=0;
gammacount=0;



monster=nullptr;
monstertimetocome = (rand()%30) +1;
ismonsteractive=false;
monsterfire = false;
cooldown=false;

turn="monster";
dragon=nullptr;
isdragonactive=false;
dragontimetocome=(rand()%15) +1;

for(int i=0; i<20; i++)
{
	alpha[i]=nullptr;
	beta[i]=nullptr;
	gamma[i]=nullptr;
}



addon[0] = new Life;
addon[1] = new Danger;
addon[2] = new Fire;
addon[3] = new Shield;
addonactive = false;

score = 0;
}
#include "draw.h"
//----------------when game is restarted all the variables are reset-----------------//
void restart()
{

	xdrag=0;
	pause="newgame";
	delete p;
	p=new Player("img/player_ship.png");
	bg_texture.loadFromFile("img/background.png");
	background.setTexture(bg_texture);
	background.setScale(2.3, 1.2);
	delete menu;
	menu = new Menu;

	level =1;
	phase = 1;
	no_alpha=0;
	no_beta=0;
	no_gamma=0;
	bombindex=100;
	alphacount=0;
	betacount=0;
	gammacount=0;



	monster=nullptr;
	monstertimetocome = (rand()%30) +1;
	ismonsteractive=false;
	monsterfire = false;
	cooldown=false;

	turn="monster";
	dragon=nullptr;
	isdragonactive=false;
	dragontimetocome=(rand()%15) +1;;




	for(int i=0; i<20; i++)
	{
		alpha[i]=nullptr;
		beta[i]=nullptr;
		gamma[i]=nullptr;
	}

	delete addon[0];
	delete addon[1];
	delete addon[2];
	delete addon[3];


	addon[0] = new Life;
	addon[1] = new Danger;
	addon[2] = new Fire;
	addon[3] = new Shield;
	addonactive = false;

	score = 0;

	for(int i=0; i<bombindex; i++)
	{
		delete bomb1[i];
	}
	for(int i=0; i<100; i++)
	{
		delete b[i];
	}

}





void start_game()
{

//------------displaying menu------------//
	if(pause!="newgame")
	{
	menu->display_mainmenu();
	level = menu->getlevel();
	playername = menu->getname();
	}

//-----------------getting the no. of inputs in the file----------//
	std::ifstream file("highscores.txt");
	int count = 0;
	std::string data;
	int sc;

	while (file >> data >> sc)
	{
		count++;
	}

	std::cout << "Number of items read from the file: " << count << std::endl;

	file.close();
//----------------------------------------------------------------------//

//-----------------score structure-------------------------------------//
    PlayerScore playerScores[++count];
    int numPlayers = readScoresFromFile(playerScores);
    playerScores[numPlayers++] = PlayerScore(playername, score);

//-----------------------------------------------------------------------

    	//------laser sound------//
    	sf::SoundBuffer buffer;
    	buffer.loadFromFile("laser.ogg");

    	sf::Sound sound;
    	sound.setBuffer(buffer);


    	//-----gameover sound------//
    	sf::Music gameover;
    	gameover.openFromFile("gameover.ogg");

//------------------------Texts and Font---------------//
	Font font;
	font.loadFromFile("OpenSans-Regular.ttf");

	Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setString("SCORE:");
	text.setPosition(950.f,100.f);

	Text Score;
	std::stringstream ss;
	ss<<score;
	Score.setFont(font);
	Score.setString(ss.str());
	Score.setCharacterSize(20);
	Score.setPosition(950.f,150.f);

	Text text2;
	text2.setFont(font);
	text2.setCharacterSize(30);
	text2.setString("LIVES:");
	text2.setPosition(950.f,200.f);

	Text Lives;
	std::stringstream ll;
	Lives.setFont(font);
	Lives.setString(ll.str());
	Lives.setCharacterSize(20);
	Lives.setPosition(950.f,250.f);

	Text text4;
	text4.setFont(font);
	text4.setCharacterSize(30);
	text4.setString("HIGHSCORE:");
	text4.setPosition(950.f,300.f);


	Text hscore1;
	Text hscore2;
	Text hscore3;
	Text hscorename1;
	Text hscorename2;
	Text hscorename3;

    std::ostringstream hiscore1, hiscore2, hiscore3;



int fireindex = 0;
int dragonindex = 0;
bool started = false;
int change = 2;
bool makemonster = false;
bool monstercollision = false;
bool dragoncollision = false;
bool collisionwithdanger=false;

//-----setting up bombs for the enemies------//
for(int i=0; i<bombindex;i++)
{
	bomb1[i]=new Bomb;
}
//--------------------------------------------

//-------setting up bullets for the player---//
for(int i=0; i<100; i++)
{
	b[i]=new Bullet;
}
//--------------------------------------------
	bool fire = false;
    srand(time(0));
    RenderWindow window(VideoMode(1200, 780), title);


    Clock clock1;    Clock clock2;     Clock clock3;  Clock clockmonster; Clock delay; Clock clockdragon;
    Clock clockaddon; Clock gameplay; Clock dragonbeam;

p->setbulletindex(0);
bool draw = false;


hscore1.setFont(font);
hscore1.setCharacterSize(25);
hscore1.setPosition(1070.f, 355.f);


hscore2.setFont(font);
hscore2.setCharacterSize(25);
hscore2.setPosition(1070.f, 405.f);

hscore3.setFont(font);
hscore3.setCharacterSize(25);
hscore3.setPosition(1070.f, 455.f);


hscorename1.setFont(font);
hscorename1.setCharacterSize(30);
hscorename1.setPosition(900.f,350.f);

hscorename2.setFont(font);
hscorename2.setCharacterSize(30);
hscorename2.setPosition(900.f,400.f);

hscorename3.setFont(font);
hscorename3.setCharacterSize(30);
hscorename3.setPosition(900.f,450.f);


//------------------------------game loop---------------------//
	while (window.isOpen())
    {

//---------------------displaying top 3 highscores-----------//
		if(count>=3)
		{
		hiscore1.str("");
		hiscore2.str("");
		hiscore3.str("");

		hiscore1<<playerScores[0].score;
		hiscore2<<playerScores[1].score;
		hiscore3<<playerScores[2].score;

		hscore1.setString(hiscore1.str());
		hscore2.setString(hiscore2.str());
		hscore3.setString(hiscore3.str());

		hscorename1.setString(playerScores[0].name);
		hscorename2.setString(playerScores[1].name);
		hscorename3.setString(playerScores[2].name);
		}
		else if(count==2)
		{
			hiscore1.str("");
			hiscore2.str("");
			hiscore1<<playerScores[0].score;
			hiscore2<<playerScores[1].score;
			hscore1.setString(hiscore1.str());
			hscore2.setString(hiscore2.str());
			hscorename1.setString(playerScores[0].name);
			hscorename2.setString(playerScores[1].name);
		}
		else if(count==1)
		{
			hiscore1.str("");
			hiscore1<<playerScores[0].score;
			hscore1.setString(hiscore1.str());
			hscorename1.setString(playerScores[0].name);
		}



    	if(started==false)
    	drawenemy(started);

    	started = true;
    	bulletindex = p->getbulletindex();

//--------uspdate bpmb speed according to level------------//
    	for(int i=0; i<bombindex; i++)
    	{
    		bomb1[i]->updatebombspeed(level);
    	}

        int alphatime = clock1.getElapsedTime().asSeconds();
        int monstertime = clockmonster.getElapsedTime().asSeconds();
        int monster_rehna=0;
        monster_rehna = delay.getElapsedTime().asSeconds();
        int dragontime = clockdragon.getElapsedTime().asSeconds();
        int addontime = clockaddon.getElapsedTime().asSeconds();


//------------------------------------Alpha enemy------------------------//
        if(!ismonsteractive&& !isdragonactive)
        {
			for(int i=0; i<no_alpha; i++)
			{
				if(alpha[i]!=nullptr)
				{
					for(int j=0; j<bombindex; j++)
					if(bomb1[j]->getactive()==false)
					{
						alpha[i]->loadbomb(*bomb1[j]);
						if(bomb1[j]->getactive()==true)
						{
							draw = true;
						}
						break;
					}
				}
			}
         }

//-----------------------------------creating beta enemy-----------//

        if(!ismonsteractive&& !isdragonactive)
		   {
			for(int i=0; i<no_beta; i++)
			{
				if(beta[i]!=nullptr)
				{
					for(int j=0; j<bombindex; j++)
					if(bomb1[j]->getactive()==false)
					{
						beta[i]->loadbomb(*bomb1[j]);
						if(bomb1[j]->getactive()==true)
						{
							draw = true;
						}
						break;
					}
				}
			}
			}

//-----------------------------------creating gamma enemy-----------//

        if(!ismonsteractive&& !isdragonactive)
		   {
			for(int i=0; i<no_gamma; i++)
			{
				if(gamma[i]!=nullptr)
				{
					for(int j=0; j<bombindex; j++)
					if(bomb1[j]->getactive()==false)
					{
						gamma[i]->loadbomb(*bomb1[j]);
						if(bomb1[j]->getactive()==true)
						{
							draw = true;
						}
						break;
					}
				}
			}
			}
//--------------------------creating monster ------------------------------------------------------------//

       if(makemonster==false)
        if(monstertime == monstertimetocome && turn=="monster")
        {
        	ismonsteractive = true;
        	monster = new Monster;
        	monster->draw(350, 0);
        	monstercollision = false;
        	delay.restart();
			makemonster = true;
			monsterfire = false;
			monstertimetocome = (rand()%27) +1;
			monster->updatespeed(level);
        }

//------if 10 secs up remove monster and change turn to dragon--------//
       if(makemonster)
       if(monster_rehna==10)
       {
		 monster->urado();
		 monster=nullptr;
		 bomb1[fireindex]->setactive(false);
		 if(!monstercollision)
		 {
			 score+=40;
		 }
		 ismonsteractive = false;
		 makemonster = false;
		 clockmonster.restart();
		 turn = "dragon";
		 clockdragon.restart();
		for(int i=0; i<bombindex; i++)
		{
			if(bomb1[i]->getactive()==true)
			{
				bomb1[i]->setactive(false);
			}
		}

       }


//----------------------------------------------------setting up dragon-----------------------------------//
if(!isdragonactive && dragontimetocome==dragontime && turn=="dragon")
{
dragoncollision = false;
dragontimetocome=(rand()%17) +1;
dragon = new Dragon;
dragon->draw(350, 0);
for(int i=80;i<bombindex;i++)
	if(bomb1[i]->getactive()==false)
	{
		dragon->loadbomb(*bomb1[i]);
		bomb1[i]->setactive(true);
		dragonindex = i;
		break;
	}
isdragonactive=true;
clockdragon.restart();
xdrag=p->getplayersprite().getPosition().x;
dragonbeam.restart();
}


//----if 5 secs up, remove dragon------//
//---change the turn to monster--------//


if(dragontime==5 && isdragonactive)//-----------------------------------------------------------------------------
{
	isdragonactive=false;
	bomb1[dragonindex]->setactive(false);
	clockmonster.restart();
	 clockdragon.restart();

	turn = "monster";
	for(int i=0; i<bombindex; i++)
	{
		if(bomb1[i]->getactive()==true)
		{
			bomb1[i]->setactive(false);
		}
	}
	if(!dragoncollision)
	 {
		 score+=50;
	 }
	dragon->urado();
	dragon=nullptr;
}

//----------change position of beam according to player's position----------------//
if(isdragonactive)
{


	if(xdrag<370 && xdrag>170 && (((int)dragonbeam.getElapsedTime().asSeconds())==1))
	{
			xdrag=p->getplayersprite().getPosition().x;
			bomb1[dragonindex]->drawbomb(dragon->returnsprite().getPosition().x + 25, dragon->returnsprite().getPosition().y + 75,"img/b.png");
			change=1;
			dragonbeam.restart();
			if(xdrag<370 && xdrag>170)
			{
				p->decrementlives();
				dragoncollision=true;
			}

	}
	if(xdrag>370 && (((int)dragonbeam.getElapsedTime().asSeconds())==1))
	{
		xdrag=p->getplayersprite().getPosition().x;

		bomb1[dragonindex]->drawbomb(dragon->returnsprite().getPosition().x + 25, dragon->returnsprite().getPosition().y + 75,"img/tiltedright.png");
		change=2;
		dragonbeam.restart();
		if(xdrag>370)
		{
			p->decrementlives();
			dragoncollision=true;
		}

	}
	if(xdrag<170 && (((int)dragonbeam.getElapsedTime().asSeconds())==1))
	{
		xdrag=p->getplayersprite().getPosition().x;

		bomb1[dragonindex]->drawbomb(dragon->returnsprite().getPosition().x - 440, dragon->returnsprite().getPosition().y + 75,"img/pop.png");
		change=3;
		dragonbeam.restart();
		if(xdrag<170)
		{
			p->decrementlives();
			dragoncollision=true;
		}

	}
}



//--------------------------------------ADD ONS----------------------------------------------//
        if(alphatime==5 && !addonactive)
        {
        	addon[0]->draw(350, -50);
        	addon[1]->draw(550, -70);
        	addon[2]->draw(150, -100);
        	addon[3]->draw(650, -150);


        	addonactive = true;
        }
        if(addonactive)
        {
        	addon[0]->move();
        	addon[1]->move();
        	addon[2]->move();
        	addon[3]->move();
        }

    if(addonactive)
    {
        if(addon[0]->getsprite().getPosition().y>=700)
        {
        	addon[0]->updateposition(1+rand()%600, -300);
        }
        if(addon[1]->getsprite().getPosition().y>=700)
		{
			addon[1]->updateposition(10+rand()%500, -700);
				score+=5;
		}
        if(addon[2]->getsprite().getPosition().y>=700)
		{
			addon[2]->updateposition(13+rand()%550, -500);
		}
        if(addon[3]->getsprite().getPosition().y>=700)
		{
			addon[3]->updateposition(16+rand()%677, -800);
		}

    }

    if(addontime==5)
	{
		p->settype("no");
	}

//----------------------collision with addon-------------------//
    if(addonactive)
    {
    	for(int i=0; i<4; i++)
    	{
    		if(p->checkcollisionwithaddon(addon[i]))
    		{
    			p->implementaddon();
    			addon[i]->updateposition(13+rand()%550, -(19+rand()%750));
    			if(p->getfiredanger()=="shield" || p->getfiredanger()=="fire")
    				clockaddon.restart();

    			if(p->getfiredanger()=="danger")
    				collisionwithdanger=true;
    			break;
    		}
    	}
    }


    if(p->gettype()=="shield")
    {
    	p->updateshield();
    }
    else if(p->gettype()=="fire")
	{
		p->updatefire();
	}


//-----------------------------------------------------------//
//--------------------EVENTS--------------------------------//
 	Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game
        }

	if (Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::D))
    		p->movediagonal("dr");
    else if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::A))
    		p->movediagonal("ul");
    else if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::D))
    		p->movediagonal("ur");
	else if (Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::A))
    		p->movediagonal("dl");

	else if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	else if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	else if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	else if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
    else
    {
    	p->correcttilt();
    }

	if((Keyboard::isKeyPressed(Keyboard::P)))
	{
		pause = menu->display_pausemenu(window);

		if (pause=="quit")
		{
			break;
		}
		else if(pause=="newgame")
		{
			window.close();
			restart();
			start_game();
		}
	}

    if (e.key.code == Keyboard::Space)
    {
    	sound.play();
    	if(p->getplayersprite().getPosition().y > 0)
		{

		fire = true;

		for(int i=0; i<100; i++)
		{
			if(b[i]->getactive()==false)
			{
				p->makebullet(*(b[i]), i);
				break;
			}
		}
		}
	}

//---------------wrap-----------//
	p->wrap();
//-------------moving bullet------//
	if(fire)
	{
		for(int i=0; i<100; i++)
		{
			if(b[i]->getactive()==true)
			{
				b[i]->movebullet();
			}
		}
	}

//----------------------------levels changing------------//
	bool changelevel = true;
	for(int i=0; i<20; i++)
	{
		if(alpha[i]!=nullptr || beta[i]!=nullptr || gamma[i]!=nullptr)
		{
			changelevel = false;
			break;
		}

	}

	if(changelevel)
	{
		if(level == 1 && phase!=3)
		{
			phase++;
		}
		else if(level==1 && phase==3)
		{
			level++;
			phase=1;
		}
		else if(level == 2 && phase!=3)
		{
			phase++;
		}
		else if(level==2 && phase==3)
		{
			level++;
			phase=1;
		}
		else if(level == 3 && phase!=6)
		{
			phase++;
		}
		else if(level == 3 && phase==6)
		{
			level=1;
			phase=1;
		}

		drawenemy(false);
	}

//-----------------moving and collision of bombs------------//

    if(!ismonsteractive && !isdragonactive)
	if(draw)
	{
		for(int i=0; i<bombindex; i++)
		{
			if(bomb1[i]->getactive()==true)
			{
			    bomb1[i]->movebomb();
			}
		}
	for(int i=0; i<bombindex; i++)
	{
		if(bomb1[i]->checkend())
		{
			bomb1[i]->setactive(false);
		}

	}

	for(int i=0; i<bombindex; i++)
	{
		if(bomb1[i]->getactive()==true)
		{
			if(p->checkcollisionwithbomb(*bomb1[i]))
			{
				p->updateplayer();
				p->decrementlives();
				p->settype("shield");
				p->setfiredanger("no");
				p->implementaddon();
				clockaddon.restart();
				for(int i=0; i<bombindex; i++)
				{
					if(bomb1[i]->getactive()==true)
					{
						bomb1[i]->setactive(false);
					}
				}
				break;
			}
		}
	}
	}


//---------------------------collision with monster beam-------------------//
    if(ismonsteractive)
    {
    	if(!cooldown)
    	{
    	if(p->checkcollisionwithbomb(*bomb1[fireindex]))
		{
			p->updateplayer();
			p->decrementlives();
			p->settype("shield");
			p->setfiredanger("no");
			p->implementaddon();
			monstercollision=true;
			clockaddon.restart();
		}

    	}
    }

//------------------collision of player with enemies---------------//


if(!ismonsteractive && !isdragonactive)
{
	for(int i=0; i<no_alpha; i++)
	{
		if(alpha[i]!=nullptr)
		if(p->checkcollisionwithenemy(alpha[i]))
		{
			p->updateplayer();
			p->decrementlives();
			p->settype("shield");
			p->setfiredanger("no");
			p->implementaddon();
			clockaddon.restart();
			break;
		}
	}

	for(int i=0; i<no_beta; i++)
	{
		if(beta[i]!=nullptr)
		if(p->checkcollisionwithenemy(beta[i]))
		{
			p->updateplayer();
			p->decrementlives();
			p->settype("shield");
			p->setfiredanger("no");
			p->implementaddon();
			clockaddon.restart();
			break;
		}
	}
	for(int i=0; i<no_gamma; i++)
	{
		if(gamma[i]!=nullptr)
		if(p->checkcollisionwithenemy(gamma[i]))
		{
			p->updateplayer();
			p->decrementlives();
			p->settype("shield");
			p->setfiredanger("no");
			p->implementaddon();
			clockaddon.restart();
			break;
		}
	}
}
if(ismonsteractive)
    {
	if(p->checkcollisionwithenemy(monster))
			{
				p->updateplayer();
				p->decrementlives();
				p->settype("shield");
				p->setfiredanger("no");
				p->implementaddon();
				clockaddon.restart();

			}
    }
else if(isdragonactive)
    {
	if(p->checkcollisionwithenemy(dragon))
			{
				p->updateplayer();
				p->decrementlives();
				p->settype("shield");
				p->setfiredanger("no");
				p->implementaddon();
				clockaddon.restart();

			}
    }


    if(ismonsteractive)
    {
    	if(monsterfire == false)
    	{
    	for(int i=50; i<bombindex; i++)
    		if(bomb1[i]->getactive()==false)
    		{
    			monster->loadbomb(*bomb1[i]);
    			bomb1[i]->setactive(true);
    			monsterfire = true;
    			fireindex = i;
    			cout<<fireindex<<endl;
    			break;
    		}
    	}
    }

//----moving monster---//
        if(ismonsteractive)
        {
        	monster->move();
        	if(monsterfire)
        	{
        		bomb1[fireindex]->updateposition(monster->returnsprite().getPosition().x+20, monster->returnsprite().getPosition().y);
        	}
        }

        if(ismonsteractive)
        {
        if(monstertime%3==0)
        {
        	cooldown = false;
        }
        else
        	cooldown = true;
        }




	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
//---------------------drawing and displaying all the text objects------------------//

    		ss.str(""); //converting score into string to display
			ss<<score;
			Score.setString(ss.str());
	        window.draw(text);
	        window.draw(Score);

	        ll.str("");
	        ll<<p->getlives();
	        Lives.setString(ll.str());
	        window.draw(text2);
	        window.draw(Lives);

	        window.draw(text4);
	        if(count>=3)
	        {
	        window.draw(hscore1);
			window.draw(hscore2);
			window.draw(hscore3);
			window.draw(hscorename1);
			window.draw(hscorename2);
			window.draw(hscorename3);
	        }
	        else if(count==2)
	        {
	        	window.draw(hscore1);
	        	window.draw(hscore2);
	        	window.draw(hscorename1);
	        	window.draw(hscorename2);
	        }
	        else if(count==1)
	        {
	        	window.draw(hscore1);
	        	window.draw(hscorename1);
	        }


//----------------------drawing bullets---------------//
	if(fire)
	{

			for(int i=0; i</*bulletindex*/100; i++)
				if(b[i]->getactive()==true)
					window.draw(p->b[i]->getsprite());
	}


//----collision of alpha with bullet---//
if(!ismonsteractive && !isdragonactive)
{
	for (int j = 0; j <100; j++)
	{
		if(b[j]->getactive())
		{
		bool match = false;
		for(int i=0; i<no_alpha; i++)
		{
			if(alpha[i]!=nullptr)
			{
				if (alpha[i]->isColliding(*(b[j])))
				{
					alpha[i]->urado();
					 score = score + (level*10);
					alphacount--;
					alpha[i]=nullptr;

					if(!(p->gettype()=="fire"))
					b[j]->setactive(false);
					match = true;
					break;
				}

			}
		}
		if(match)
			break;
		}
	}


//----collision of beta with bullet---//

	for (int j = 0; j <100; j++)
		{
		if(b[j]->getactive())
		{
			bool match = false;
			for(int i=0; i<no_beta; i++)
			{
				if(beta[i]!=nullptr)
				{
					if (beta[i]->isColliding(*(b[j])))
					{
						beta[i]->urado();
						score = score + (level*20);
						beta[i]=nullptr;
						betacount--;
						if(!(p->gettype()=="fire"))
						b[j]->setactive(false);

						match = true;

						break;
					}

				}
			}
			if(match)
				break;
		}
		}

//----collision of gamma with bullet---//

	for (int j = 0; j <100; j++)
		{
		if(b[j]->getactive())
		{
			bool match = false;
			for(int i=0; i<no_gamma; i++)
			{
				if(gamma[i]!=nullptr)
				{
					if (gamma[i]->isColliding(*(b[j])))
					{
						gamma[i]->urado();
						score = score + (level*30);
						gamma[i]=nullptr;
						gammacount--;
						if(!(p->gettype()=="fire"))
						b[j]->setactive(false);

						match = true;

						break;
					}

				}
			}
			if(match)
				break;
		}
		}
}

// checking for destroying bullet

if(fire)
{
	for(int i=0; i<100; i++)
	{
		if(b[i]->getactive()==true)
		{
			if(b[i]->checkend())
			{
				b[i]->setactive(false);
			}
		}
	}
}




//----------------------score update and sort----------------------//

for(int i=0; i < numPlayers; i++)
{
	if(playerScores[i].name==this->playername)
	{
		playerScores[i].score=this->score;
	}
}
bubbleSort(playerScores, numPlayers);





//--------Drawing all the sprites-----------//


		window.draw(p->getplayersprite());   // setting player on screen
		if(p->gettype()=="shield")
		{
			window.draw(p->getshield());
		}
		else if(p->gettype()=="fire")
		{
			window.draw(p->getfire());
		}




     if((!ismonsteractive) && (!isdragonactive))
     {
		if(draw)
		for(int i =0; i<bombindex; i++)
		{
			if(bomb1[i]->getactive()==true)
			window.draw(bomb1[i]->getsprite());
		}


		for(int i=0; i<no_alpha; i++)
		if(alpha[i]!=nullptr)
		window.draw(alpha[i]->returnsprite());
		for(int i=0; i<no_beta; i++)
		if(beta[i]!=nullptr)
		window.draw(beta[i]->returnsprite());
		for(int i=0; i<no_gamma; i++)
		if(gamma[i]!=nullptr)
		window.draw(gamma[i]->returnsprite());
     }
     else if(ismonsteractive)
     {
    	 if(monsterfire)
    	 {

    		 if(!cooldown)
    		 window.draw(bomb1[fireindex]->getsprite());

    	 }
    	 window.draw(monster->returnsprite());

     }

     else if(isdragonactive)
     {
    	 window.draw(dragon->returnsprite());
		 window.draw(bomb1[dragonindex]->getsprite());

     }

     if(addonactive)
     {
    	 window.draw(addon[0]->getsprite());
    	 window.draw(addon[1]->getsprite());
    	 window.draw(addon[2]->getsprite());
    	 window.draw(addon[3]->getsprite());
     }


     if(p->getlives()<=0)
     {
    	 gameover.play();
    	 pause = menu->display_gameovermenu(window);
    	 if(pause == "quit")
    		 break;
    	 else if(pause=="newgame")
    	 {
    		 window.close();
    		 restart();
    		 start_game();
    	 }
     }


		window.display();  //Displying all the sprites

    }

 //----------------writing the scores back to file-----------------//
    writeScoresToFile(playerScores, numPlayers);

}


};
