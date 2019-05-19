#ifndef __MAINMENUSTATE_HPP__
#define __MAINMENUSTATE_HPP__

#include "GameState.hpp"
#include "GameEngine.hpp"

class MainMenuState : public GameState {
    public:
        void init();
        void cleanup();

        void pause();
        void resume();

        void handleEvents(GameEngine*);
        void update(GameEngine*);
        void render(GameEngine*);

        static MainMenuState* instance(){
            static MainMenuState MainMenuStateInstance;
            return &MainMenuStateInstance;
        }
    
    protected:
        MainMenuState(){}

    private:

};


#endif // __MAINMENUSTATE_HPP__
