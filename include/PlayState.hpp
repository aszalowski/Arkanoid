#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.hpp"
#include "GameEngine.hpp"

class PlayState : public GameState {
    public:
        void init(GameEngine *game);
        void cleanup(GameEngine *game);

        void pause();
        void resume();

        void handleEvents(GameEngine*);
        void update(GameEngine*);
        void render(GameEngine*);

        static PlayState* instance(){
            static PlayState PlayStateInstance;
            return &PlayStateInstance;
        }
    
    protected:
        PlayState(){}

};












#endif