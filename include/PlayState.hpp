#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.hpp"
#include "GameEngine.hpp"

class PlayState : public GameState {
    public:
        void init();
        void cleanup();

        void pause();
        void resume();

        void handleEvents(GameEngine*);
        void update(GameEngine*);
        void render(GameEngine*);

        inline static PlayState* instance(){ return &PlayStateInstance; }
    
    protected:
        PlayState(){}
    
    private:
        static PlayState PlayStateInstance;


};












#endif