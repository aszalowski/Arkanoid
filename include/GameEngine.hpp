#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Ball.hpp"

class GameState;

class GameEngine
{
public:
	GameEngine(int width, int height, std::string title, std::string iconPath, int frameLimit, bool vsync);
	~GameEngine() { std::cout << "GameEngine destructor" << std::endl; };

	void changeState(GameState *state);
	void pushState(GameState *state);
	void popState();

	void handleEvents();
	void update();
	void render();

	inline bool running() { return m_running; }
	inline void quit() { m_running = false; }

	sf::RenderWindow window;

	Player p1, p2;
	Ball ball;

	void resetClock() { Clock.restart(); }
	void setElapsedTime() { elapsedTime = Clock.getElapsedTime().asMilliseconds(); }
	const uint getElapsedTime() const { return elapsedTime; }

private:
	sf::Clock Clock;
	uint elapsedTime;
	std::vector<GameState *> states;

	bool m_running;
	bool m_fullscreen;
};

#endif