#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "../include/Collision.hpp"
#include "../include/GameEngine.hpp"
#include "../include/PlayState.hpp"
#include "../include/MainMenuState.hpp"

int main(int, char const**)
{
    GameEngine game(640, 360, 1920, 1080, "Arkanoid", "resources/icon.png", 60, true);

    game.changeState(MainMenuState::instance());
;


    while( game.running() ){
        game.resetClock();
        game.handleEvents();
        game.update();
        game.render();
        game.setElapsedTime();
        game.window.clear();
    }
}
