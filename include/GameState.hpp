#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameEngine.hpp"

class GameState{
    public:
        virtual void init(GameEngine* game) = 0;
        virtual void cleanup(GameEngine* game) = 0;
        
        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void handleEvents(GameEngine*) = 0;
        virtual void update(GameEngine*) = 0;
        virtual void render(GameEngine*) = 0;

        void changeState(GameEngine* game, GameState* state){
            game->changeState(state);
        }
    
    protected:
        GameState(){}

};


#endif