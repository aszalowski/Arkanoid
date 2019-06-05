#ifndef __ENDGAMESTATE_HPP__
#define __ENDGAMESTATE_HPP__

#include <SFML/Graphics.hpp>

#include "BaseMenuState.hpp"
///State after winning or loosing a game
class EndGameState : public BaseMenuState
{
    public:
        void init(GameEngine *game);

        bool isTransparent(){ return true; } ///< Checks if transparent

        static EndGameState* instance()
        {
            static EndGameState EndGameStateInstance;
            return &EndGameStateInstance;
        }

    private:
        sf::Text title; ///< Text who wins/looses

    protected:
        EndGameState(){}

};

#endif // __ENDGAMESTATE_HPP__
