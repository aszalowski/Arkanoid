#ifndef __MAINMENUSTATE_HPP__
#define __MAINMENUSTATE_HPP__

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "GameState.hpp"
#include "Buttons.hpp"


class MainMenuState : public GameState {
    public:
        void init(GameEngine *game);
        void cleanup(GameEngine* game);

        void pause();
        void resume();

        void handleEvents(GameEngine*, sf::Event);
        void update(GameEngine*);
        void render(GameEngine*);

        static MainMenuState* instance(){
            static MainMenuState MainMenuStateInstance;
            return &MainMenuStateInstance;
        }
    
    protected:
        MainMenuState(){}

    private:
        std::vector<std::shared_ptr<Button>> buttons; 
        sf::Font* font;
        uint mediumFontSize = 25;




};


#endif // __MAINMENUSTATE_HPP__
