#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

#include "GameEngine.hpp"

class GameState
{
public:
    virtual void init(GameEngine *game) = 0;    ///< Initializes GameState
    virtual void cleanup(GameEngine *game) = 0; ///< Clean-ups after GameState

    virtual void pause() = 0;  ///< Pauses GameState
    virtual void resume() = 0; ///< Resumes GameState

    virtual void handleEvents(GameEngine *, sf::Event) = 0; ///< Handle events like key presses or closing the window
    virtual void update(GameEngine *) = 0;                  ///< Updates objects used in the GameState - positions, textures
    virtual void render(GameEngine *) = 0;                  ///< Draws objects into the single frame

    virtual bool isTransparent() { return false; }

    void changeState(GameEngine *game, GameState *state)    ///< Changes GameState
    {
        game->changeState(state);
    }

protected:
    GameState() {}
};

#endif