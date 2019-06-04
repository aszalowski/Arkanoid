#ifndef __BaseMENUSTATE_HPP__
#define __BaseMENUSTATE_HPP__

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "GameState.hpp"
#include "Buttons.hpp"

///Class of all menus

class BaseMenuState : virtual public GameState {
    public:
        BaseMenuState(){ std::cout << "BaseMenuState()" << std::endl; }
        ~BaseMenuState(){ std::cout << "~BaseMenuState()" << std::endl; }

        void init(GameEngine *game){};
        void cleanup(GameEngine* game);

        void pause();
        void resume();

        void handleEvents(GameEngine*, sf::Event);
        void update(GameEngine*);
        void render(GameEngine*);

        // static BaseMenuState* instance(){
        //     static BaseMenuState BaseMenuStateInstance;
        //     return &BaseMenuStateInstance;
        // }
    
    protected:

        std::vector<std::shared_ptr<Button>> buttons; 
        std::vector<sf::Drawable*> objects;
        sf::Font* font;
        const static uint mediumFontSize = 25;




};


#endif // __BaseMENUSTATE_HPP__
