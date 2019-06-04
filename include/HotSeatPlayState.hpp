#ifndef HOTSEATPLAYSTATE_H
#define HOTSEATPLAYSTATE_H

#include "GameState.hpp"
#include "GameEngine.hpp"
#include "PlayState.hpp"

///Play state for 2 players - uses PlayState
class HotSeatPlayState : public PlayState
{
private:
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
};

#endif