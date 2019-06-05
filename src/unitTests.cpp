#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"

#include <SFML/Graphics.hpp>

#include "../include/Buttons.hpp"


TEST_CASE(" Testing member functions Button and TextButton")
{
    sf::Texture emptyTexture;
    sf::Text emptyText;

    Button button(&emptyTexture, sf::Color::White, sf::Vector2f(0, 0));
    TextButton tbutton(&emptyTexture, sf::Color::White, sf::Vector2f(0, 0), emptyText);

    SECTION("Button")
    {
        REQUIRE( button.getPosition().x == 0 );
        REQUIRE( button.getPosition().y == 0 );

        button.setPosition(sf::Vector2f(15, 10));

        REQUIRE( button.getPosition().x == 15.0 );
        REQUIRE( button.getPosition().y == 10.0 );

    }

    SECTION("TextButton")
    {
        REQUIRE( tbutton.getPosition().x == 0 );
        REQUIRE( tbutton.getPosition().y == 0 );

        tbutton.setPosition(sf::Vector2f(15, 10));

        REQUIRE( tbutton.getPosition().x == 15.0 );
        REQUIRE( tbutton.getPosition().y == 10.0 );

    }
}