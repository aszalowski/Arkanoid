#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"

#include <SFML/Graphics.hpp>

#include "../include/Buttons.hpp"
#include "../include/Player.hpp"
#include "../include/GameEngine.hpp"

GameEngine testGame(500, 300, 100, 600, "AAA", "resources/icon.png", 60, 0);

TEST_CASE(" Testing member functions Button and TextButton")
{
    sf::Texture emptyTexture;
    sf::Text emptyText;

    Button button(&emptyTexture, sf::Color::White, sf::Vector2f(0, 0));
    TextButton tbutton(&emptyTexture, sf::Color::White, sf::Vector2f(0, 0), emptyText);

    SECTION("Button")
    {
        REQUIRE(button.getPosition().x == 0);
        REQUIRE(button.getPosition().y == 0);

        button.setPosition(sf::Vector2f(15, 10));

        REQUIRE(button.getPosition().x == 15.0);
        REQUIRE(button.getPosition().y == 10.0);
    }

    SECTION("TextButton")
    {
        REQUIRE(tbutton.getPosition().x == 0);
        REQUIRE(tbutton.getPosition().y == 0);

        tbutton.setPosition(sf::Vector2f(15, 10));

        REQUIRE(tbutton.getPosition().x == 15.0);
        REQUIRE(tbutton.getPosition().y == 10.0);
    }
}

TEST_CASE("Testing class Player")
{
    SECTION("Controls")
    {
        Controls testControls(sf::Keyboard::A, sf::Keyboard::S, sf::Keyboard::D);
        REQUIRE(testControls.left == sf::Keyboard::A);
        REQUIRE(testControls.right == sf::Keyboard::S);
        REQUIRE(testControls.start == sf::Keyboard::D);
    }
    SECTION("Player")
    {
        Player testPlayer(1, sf::Keyboard::A, sf::Keyboard::S, sf::Keyboard::D);
        sf::Vector2f testPos(100, 50);
        int testScore = 6344523;
        int addScore = 1435;
        int testHp = 3212312;
        float testMoveStep = 0.4342;
        sf::IntRect textureRect(0, 0, 110, 25);
        int side = -1;
        uint time = 10;
        std::shared_ptr<sf::Texture> testTexture = testGame.textureMenager.get("paddle.png");

        testPlayer.setPosition(testPos);
        testPlayer.setTexture(&testGame, "paddle.png", textureRect);
        testPlayer.setScore(testScore);
        testPlayer.setHp(testHp);
        testPlayer.setMoveStep(testMoveStep);

        REQUIRE(testPlayer.getPosition() == testPos);
        REQUIRE(testPlayer.getSprite().getTexture() == testTexture.get());
        REQUIRE(testPlayer.getScore() == testScore);
        REQUIRE(testPlayer.getHp() == testHp);
        REQUIRE(testPlayer.getMoveStep() == testMoveStep);
        REQUIRE(testPlayer.modifySprite().getTextureRect() == textureRect);

        testPlayer--;
        testPlayer += addScore;
        testPlayer.move(side, testGame.getVirtualSize(), time);

        REQUIRE(testPlayer.getHp() == --testHp);
        REQUIRE(testPlayer.getScore() == (testScore += addScore));
        REQUIRE(testPlayer.modifySprite().getPosition().x == (testPos.x + (side * testMoveStep * time)));
    }
}

TEST_CASE("Testing Ball class")
{
    Ball testBall;
    sf::Vector2f position(34, 453), speed(0.35, -0.12), changeSpeed(-2, 1.5);
    std::shared_ptr<sf::Texture> texture = testGame.textureMenager.get("ball.png");
    sf::IntRect textureRect(0, 0, 20, 20);
    uint time = 10;

    testBall.setPosition(position);
    testBall.setSpeed(speed);
    testBall.setTexture(&testGame, "ball.png", textureRect);

    REQUIRE(testBall.getPosition() == position);
    REQUIRE(testBall.getSpeed() == speed);
    REQUIRE(testBall.getSprite().getTexture() == texture.get());
    REQUIRE(testBall.modifySprite().getTextureRect() == textureRect);

    testBall.moveX(time);
    sf::Vector2f newPosition((position.x + (time * speed.x)), position.y);
    REQUIRE(testBall.getPosition() == newPosition);

    testBall.moveY(time);
    newPosition = sf::Vector2f(newPosition.x, newPosition.y + time * speed.y);
    REQUIRE(testBall.getPosition() == newPosition);

    testBall *= changeSpeed;
    REQUIRE(testBall.getSpeed().x == speed.x * changeSpeed.x);
    REQUIRE(testBall.getSpeed().y == speed.y * changeSpeed.y);
}

