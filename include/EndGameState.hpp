#ifndef __ENDGAMESTATE_HPP__
#define __ENDGAMESTATE_HPP__

#include <SFML/Graphics.hpp>

#include "BaseMenuState.hpp"

class EndGameState : public BaseMenuState
{
    public:
        void init(GameEngine *game);

        bool isTransparent(){ return true; }

        static EndGameState* instance()
        {
            static EndGameState EndGameStateInstance;
            return &EndGameStateInstance;
        }

    private:
        sf::Text title;

    protected:
        EndGameState(){}

};

#endif // __ENDGAMESTATE_HPP__
