
#ifndef PauseSTATE_H
#define PauseSTATE_H

#include <SFML/Graphics.hpp>

#include "BaseMenuState.hpp"
#include "GameEngine.hpp"

class PauseState : public BaseMenuState {
    public:
        void init(GameEngine *game);

        bool isTransparent(){ return true; }

        static PauseState* instance(){
            static PauseState PauseStateInstance;
            return &PauseStateInstance;
        }
    
    protected:
        PauseState(){}

};

#endif