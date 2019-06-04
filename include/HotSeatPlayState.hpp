#ifndef HOTSEATPLAYSTATE_H
#define HOTSEATPLAYSTATE_H

#include "GameState.hpp"
#include "GameEngine.hpp"
#include "PlayState.hpp"


class HotSeatPlayState :  public PlayState
{
public:
    void init(GameEngine *game);
    void cleanup(GameEngine *game);

    void pause();
    void resume();

    void handleEvents(GameEngine *, sf::Event);
    void update(GameEngine *);
    void render(GameEngine *);

    static HotSeatPlayState *instance()
    {
        static HotSeatPlayState HotSeatPlayStateInstance;
        return &HotSeatPlayStateInstance;
    }

protected:
    HotSeatPlayState() {}

    private:
        sf::Font* font;
        std::vector<sf::Sprite> hearts;
        sf::Text score;
};

#endif