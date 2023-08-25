
#include <iostream>
#include "playerscore.h"

using namespace std;

using namespace sf;
class Menu{
	int level;
	bool select;
	string username;
public:

//add menu attributes here

Menu()
{
level = 0;
select = true;
username = "";
//constructors body
}

int getlevel()
{
	return level;
}
string getname()
{
	return username;
}

void display_mainmenu()
{
    RenderWindow windowa(VideoMode(1200, 780), "menu");
    sf::Font font;
    font.loadFromFile("OpenSans-Regular.ttf");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(950.f, 250.f);

    bool takingInput = false;

    Texture obj1, obj2, obj3, obj4,obj5;
    obj1.loadFromFile("menu/menu.png");
    obj2.loadFromFile("menu/howtoplay.png");
    obj3.loadFromFile("menu/instructions.png");
    obj4.loadFromFile("menu/levels.png");
    obj5.loadFromFile("menu/black.png");



    std::ifstream file("highscores.txt");
    	int count = 0;
    	int stop = 0;
    	std::string data;
    	int score;

    	while (file >> data >> score)
    	{
    		count++;
    		if (count<=5)
    			stop++;
    	}

    	std::cout << "Number of items read from the file: " << count << std::endl;
    	file.close();
    //----------------------------------------------------------------------//

    //-----------------score structure-------------------------------------//
        PlayerScore playerScores[++count];
        int numPlayers = readScoresFromFile(playerScores);

    //-----------------------------------------------------------------------



    Sprite menu(obj1), howtoplay(obj2), ins(obj3), level(obj4),highscore(obj5);



    Text hscore1;
	Text hscore2;
	Text hscore3;
	Text hscore4;
	Text hscore5;

	Text hscorename1;
	Text hscorename2;
	Text hscorename3;
	Text hscorename4;
	Text hscorename5;


	std::ostringstream hiscore1, hiscore2, hiscore3,hiscore4, hiscore5;

	hscore1.setFont(font);
	hscore1.setCharacterSize(25);
	hscore1.setPosition(500.f, 250.f);


	hscore2.setFont(font);
	hscore2.setCharacterSize(25);
	hscore2.setPosition(500.f, 350.f);

	hscore3.setFont(font);
	hscore3.setCharacterSize(25);
	hscore3.setPosition(500.f, 450.f);

	hscore4.setFont(font);
	hscore4.setCharacterSize(25);
	hscore4.setPosition(500.f, 550.f);

	hscore5.setFont(font);
	hscore5.setCharacterSize(25);
	hscore5.setPosition(500.f, 650.f);


	hscorename1.setFont(font);
	hscorename1.setCharacterSize(30);
	hscorename1.setPosition(300.f,250.f);

	hscorename2.setFont(font);
	hscorename2.setCharacterSize(30);
	hscorename2.setPosition(300.f,350.f);

	hscorename3.setFont(font);
	hscorename3.setCharacterSize(30);
	hscorename3.setPosition(300.f,450.f);

	hscorename4.setFont(font);
	hscorename4.setCharacterSize(30);
	hscorename4.setPosition(300.f,550.f);


	hscorename5.setFont(font);
	hscorename5.setCharacterSize(30);
	hscorename5.setPosition(300.f,650.f);

	hiscore1.str("");
	hiscore2.str("");
	hiscore3.str("");
	hiscore4.str("");
	hiscore5.str("");



	switch(stop)
	{
	case 1:
		{
			hiscore1<<playerScores[0].score;
			hscore1.setString(hiscore1.str());
			hscorename1.setString(playerScores[0].name);
			break;
		}
	case 2:
		{
			hiscore1<<playerScores[0].score;
			hiscore2<<playerScores[1].score;
			hscore1.setString(hiscore1.str());
			hscore2.setString(hiscore2.str());
			hscorename1.setString(playerScores[0].name);
			hscorename2.setString(playerScores[1].name);
			break;
		}
	case 3:
		{
			hiscore1<<playerScores[0].score;
			hiscore2<<playerScores[1].score;
			hiscore3<<playerScores[2].score;
			hscore1.setString(hiscore1.str());
			hscore2.setString(hiscore2.str());
			hscore3.setString(hiscore3.str());
			hscorename1.setString(playerScores[0].name);
			hscorename2.setString(playerScores[1].name);
			hscorename3.setString(playerScores[2].name);

			break;
		}
	case 4:
		{
			hiscore1<<playerScores[0].score;
			hiscore2<<playerScores[1].score;
			hiscore3<<playerScores[2].score;
			hiscore4<<playerScores[3].score;
			hscore1.setString(hiscore1.str());
			hscore2.setString(hiscore2.str());
			hscore3.setString(hiscore3.str());
			hscore4.setString(hiscore4.str());
			hscorename1.setString(playerScores[0].name);
			hscorename2.setString(playerScores[1].name);
			hscorename3.setString(playerScores[2].name);
			hscorename4.setString(playerScores[3].name);
			break;
		}
	case 5:
		{
			hiscore1<<playerScores[0].score;
			hiscore2<<playerScores[1].score;
			hiscore3<<playerScores[2].score;
			hiscore4<<playerScores[3].score;
			hiscore5<<playerScores[4].score;
			hscore1.setString(hiscore1.str());
			hscore2.setString(hiscore2.str());
			hscore3.setString(hiscore3.str());
			hscore4.setString(hiscore4.str());
			hscore5.setString(hiscore5.str());
			hscorename1.setString(playerScores[0].name);
			hscorename2.setString(playerScores[1].name);
			hscorename3.setString(playerScores[2].name);
			hscorename4.setString(playerScores[3].name);
			hscorename5.setString(playerScores[4].name);
			break;
		}
	}


    while (windowa.isOpen())
    {
        windowa.draw(menu);

        Event ev;
        while (windowa.pollEvent(ev))
                {
                    if (ev.type == Event::Closed) // If cross/close is clicked/pressed
                        windowa.close(); //close the game
                }

        if (Keyboard::isKeyPressed(Keyboard::Enter))
        {

                while (select)
                {
                	windowa.draw(level);
                    //windowa.draw(text);
                    windowa.display();

                    if (Keyboard::isKeyPressed(Keyboard::Num1))
                    {
                        this->level = 1;
                        select = false;
                    }
                    else if (Keyboard::isKeyPressed(Keyboard::Num2))
                    {
                        this->level = 2;
                        select = false;
                    }
                    else if (Keyboard::isKeyPressed(Keyboard::Num3))
                    {
                        this->level = 3;
                        select = false;
                    }
                }

                cout<<"ENTER: "<<endl;
                cin>>username;
                cout<<username<<endl;

                return;

        }
        else if (Keyboard::isKeyPressed(Keyboard::Num1))
        {
            windowa.draw(howtoplay);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num3))
        {
            windowa.draw(ins);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num2))
		{
			windowa.draw(highscore);

			switch(stop)
			{
			case 1:
				{
					windowa.draw(hscore1);
					windowa.draw(hscorename1);
					break;
				}
			case 2:
				{
					windowa.draw(hscore1);
					windowa.draw(hscore2);
					windowa.draw(hscorename1);
					windowa.draw(hscorename2);
					break;
				}
			case 3:
				{
					windowa.draw(hscore1);
					windowa.draw(hscore2);
					windowa.draw(hscore3);
					windowa.draw(hscorename1);
					windowa.draw(hscorename2);
					windowa.draw(hscorename3);
					break;
				}
			case 4:
				{
					windowa.draw(hscore1);
					windowa.draw(hscore2);
					windowa.draw(hscore3);
					windowa.draw(hscore4);
					windowa.draw(hscorename1);
					windowa.draw(hscorename2);
					windowa.draw(hscorename3);
					windowa.draw(hscorename4);
					break;
				}
			case 5:
				{
					windowa.draw(hscore1);
					windowa.draw(hscore2);
					windowa.draw(hscore3);
					windowa.draw(hscore4);
					windowa.draw(hscore5);
					windowa.draw(hscorename1);
					windowa.draw(hscorename2);
					windowa.draw(hscorename3);
					windowa.draw(hscorename4);
					windowa.draw(hscorename5);
					break;
				}

			}
		}

        windowa.display();
    }
}


string display_pausemenu(RenderWindow& windowa)
{
		Texture obj1;
		obj1.loadFromFile("menu/pause.png");




		Sprite menu(obj1);

		while(windowa.isOpen())
		{

	windowa.draw(menu);
	Event ev;
	        while (windowa.pollEvent(ev))
	        {
	            if (ev.type == Event::Closed)
	            {
	                windowa.close(); //close the game
	            }
	       }
	        if (Keyboard::isKeyPressed(Keyboard::Num1))
	        {


	        	return "resume";
	        }
	        else if (Keyboard::isKeyPressed(Keyboard::Num2))
			{
	        	return "newgame";
			}
	        else if (Keyboard::isKeyPressed(Keyboard::Num3))
			{
	        	return "quit";
			}

	        windowa.display();
		}

		return " ";
}

string display_gameovermenu(RenderWindow& windowa)
{
	Texture obj1;
	obj1.loadFromFile("menu/gameend.png");
			Sprite menu(obj1);

			while(windowa.isOpen())
			{

		windowa.draw(menu);
		Event ev;
		        while (windowa.pollEvent(ev))
		        {
		            if (ev.type == Event::Closed)
		            {
		                windowa.close(); //close the game
		            }
		       }
		        if (Keyboard::isKeyPressed(Keyboard::Num1))
		        {
		        	return "newgame";
		        }
		        else if (Keyboard::isKeyPressed(Keyboard::Num2))
				{
		        	return "quit";
				}


		        windowa.display();
			}

			return " ";
}

};
