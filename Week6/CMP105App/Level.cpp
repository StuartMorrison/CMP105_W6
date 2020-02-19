#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	gravBallText.loadFromFile("gfx/Beach_Ball.png");

	gravball.setTexture(&gravBallText);
	gravball.setSize(sf::Vector2f(100, 100));
	gravball.setPosition(100, 100);

	gravball.setInput(input);
	gravball.setWindu(window);


	pointBallText.loadFromFile("gfx/sonic.png");

	pointball.setTexture(&pointBallText);
	pointball.setSize(sf::Vector2f(50, 50));
	pointball.setPosition(50, 50);

	pointball.setWindu(window);
	pointball.setInput(input);



}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

	gravball.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{

	gravball.update(dt);
	pointball.update(dt);

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(gravball);
	window->draw(pointball);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}