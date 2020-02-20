#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "Gravball.h"
#include "Pointball.h"
#include "Angrybird.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// More level variables
	Gravball gravball;
	sf::Texture gravBallText;

	sf::Texture pointBallText;
	Pointball pointball;

	Angrybird angrybird;
	sf::Texture birdText;

	sf::Font font;
	sf::Text text;
	sf::Text displayDist;


};