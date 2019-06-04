#ifndef __HotSeatMenuSTATE_HPP__
#define __HotSeatMenuSTATE_HPP__

#include "BaseMenuState.hpp"
#include "Buttons.hpp"
#include "SpriteManager.hpp"

///Menu state in the HotSeat mode
class HotSeatMenuState : public BaseMenuState
{
    public:
        void init(GameEngine* game);
        void cleanup(GameEngine* game);

        static HotSeatMenuState* instance()
        {
            static HotSeatMenuState HotSeatMenuStateInstance;
            return &HotSeatMenuStateInstance;
        }
    
        SpriteManager P1skinChooser;
        SpriteManager P2skinChooser;
        SpriteManager ballChooser;
};

#endif // __HotSeatMenuSTATE_HPP__
