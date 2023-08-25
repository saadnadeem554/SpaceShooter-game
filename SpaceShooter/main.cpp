//#include "menu.h"
#include <SFML/Audio.hpp>
#include "game.h"
using namespace sf;
int main()
{

	sf::Music music;
	music.openFromFile("music.ogg");
    music.setLoop(true);
    music.setVolume(50);
	music.play();

    Game g;
    g.start_game();
    return 0;
}
