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


	birdText.loadFromFile("gfx/Goomba.png");

	angrybird.setTexture(&birdText);
	angrybird.setSize(sf::Vector2f(50, 50));
	angrybird.setPosition(50, 50);

	angrybird.setWindu(window);
	angrybird.setInput(input);



}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

	gravball.handleInput(dt);
	angrybird.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{

	gravball.update(dt);
	pointball.update(dt);
	angrybird.update(dt);

}

// Render level
void Level::render()
{
	beginDraw();

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	std::string xVal = std::to_string(angrybird.lcoordX);
	std::string yVal = std::to_string(angrybird.lcoordY);
	//std::string dVal = std::to_string(angrybird.distance);

	text.setFont(font);
	text.setString(xVal + ", " + yVal);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(0, 0);

	if (input->isMouseLDown())
	{
		displayDist.setFont(font);
		//displayDist.setString(dVal);
		displayDist.setCharacterSize(24);
		displayDist.setFillColor(sf::Color::Red);
		displayDist.setPosition(0, 25);
	}


	window->draw(text);
	window->draw(displayDist);

	window->draw(gravball);
	window->draw(pointball);
	window->draw(angrybird);

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