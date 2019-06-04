#ifndef __SERVESTATE_HPP__
#define __SERVESTATE_HPP__

#include <list>

#include "GameState.hpp"
#include "GameEngine.hpp"
#include "Block.hpp"

class ServeState : public GameState
{
    public:
        void init(GameEngine *game);
        void cleanup(GameEngine *game);

        void pause();
        void resume();

        void handleEvents(GameEngine *, sf::Event);
        void update(GameEngine *);
        void render(GameEngine *);

        static ServeState *instance()
        {
            static ServeState ServeStateInstance;
            return &ServeStateInstance;
        }

        bool isTransparent(){ return true; }

    protected:
        ServeState() {}

    private:
        sf::Font* font;
        sf::Text score;
        std::vector<sf::Sprite> hearts;
};

#endif // __SERVESTATE_HPP__