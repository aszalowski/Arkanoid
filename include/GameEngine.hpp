#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameState.hpp"


class GameEngine
{
public:
	GameEngine(int width, int height, std::string title, std::string iconPath, int frameLimit, bool vsync);
	~GameEngine(){ std::cout << "GameEngine destructor" << std::endl; };

	void changeState(GameState* state);
	void pushState(GameState* state);
	void popState();

	void handleEvents();
	void update();
	void render();

	inline bool running() { return m_running; }
	inline void quit() { m_running = false; }

    sf::RenderWindow window;


private:
	std::vector<GameState*> states;

	bool m_running;
	bool m_fullscreen;
};

#endif