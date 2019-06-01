#ifndef __SINGLEMENUSTATE_HPP__
#define __SINGLEMENUSTATE_HPP__

#include "BaseMenuState.hpp"
#include "Buttons.hpp"
#include "SpriteManager.hpp"


class SingleMenuState : public BaseMenuState
{
    public:
        void init(GameEngine* game);
        void cleanup(GameEngine* game);

        static SingleMenuState* instance()
        {
            static SingleMenuState SingleMenuStateInstance;
            return &SingleMenuStateInstance;
        }
    
        SpriteManager skinChooser;
        SpriteManager ballChooser;
};

#endif // __SINGLEMENUSTATE_HPP__
