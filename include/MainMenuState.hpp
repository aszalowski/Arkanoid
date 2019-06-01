#ifndef __MAINMENUSTATE_HPP__
#define __MAINMENUSTATE_HPP__

#include "BaseMenuState.hpp"
#include "Buttons.hpp"

class MainMenuState : public BaseMenuState
{
    public:
        void init(GameEngine* game);

        static MainMenuState* instance()
        {
            static MainMenuState MainMenuStateInstance;
            return &MainMenuStateInstance;
        }
    
    private:
};

#endif // __MAINMENUSTATE_HPP__
