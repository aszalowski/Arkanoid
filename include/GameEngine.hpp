#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <list>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Ball.hpp"
#include "ResourceMenager.hpp"
#include "Block.hpp"

class GameState;

class GameEngine ///Stores crucial game parts: Player, Ball, Block, GameState, Window
{
public:
	GameEngine(int virtualWidth, int virtualHeight, int width, int height, std::string title, std::string iconPath, int frameLimit, bool vsync);
	~GameEngine() { std::cout << "GameEngine destructor" << std::endl; };

	void changeState(GameState *state); ///< Changes GameState, destructing old GameState
	void pushState(GameState *state);   ///< Quick change of GameState, easy to go back to the old one
	void popState();					///< Going back to the old GameState after pushState

	void handleEvents(); ///< More about in: GameState::handleEvents()
	void update();		 ///< More about in: GameState::update()
	void render();		 ///< More about in: GameState::render()

	inline bool running() { return m_running; } ///< Returns true if game is running
	inline void quit() { m_running = false; }   ///< Sets m_running value to false, what quits the game

	sf::RenderWindow window; ///< Main window, where's everything rendered
	const sf::Vector2u &getVirtualSize() const { return virtualSize; };

	Player p1, p2;
	Ball ball;
	ResourceMenager<sf::Texture> textureMenager;
	ResourceMenager<sf::Font> fontMenager;

	std::list<Block> blocks;
	void resetClock() { Clock.restart(); }											 ///< Resets clock used for timing frames
	void setElapsedTime() { elapsedTime = Clock.getElapsedTime().asMilliseconds(); } ///< Saves time between last rendered frames
	const uint getElapsedTime() const { return elapsedTime; }						 ///< Gets saved time between last rendered frames
	float getScreenRatio() const { return (float)virtualSize.x / window.getSize().x; };

private:
	sf::Clock Clock;				 ///< Clock used for measuring frame render time
	uint elapsedTime;				 ///< Time between two rendered frames (used for fluent objects movement)
	std::vector<GameState *> states; ///< Vector of all GameStates
	sf::Vector2u virtualSize;		 ///< Real size of the window, than scaled up to obtain pixel art style

	bool m_running; ///< Stores if game is still running
};

#endif