#ifndef __SERVESTATE_HPP__
#define __SERVESTATE_HPP__

#include <list>

#include "GameState.hpp"
#include "GameEngine.hpp"
#include "Block.hpp"

class ServeState : public GameState
{
private:

public:
    void init(GameEngine *game);
    void cleanup(GameEngine *game);

    void pause();
    void resume();

    void handleEvents(GameEngine *);
    void update(GameEngine *);
    void render(GameEngine *);

    static ServeState *instance()
    {
        static ServeState ServeStateInstance;
        return &ServeStateInstance;
    }

protected:
    ServeState() {}
};

#endif // __SERVESTATE_HPP__