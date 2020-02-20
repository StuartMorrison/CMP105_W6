#include "Angrybird.h"

Angrybird::Angrybird()
{

	speed = 50.f;
	acceleration = 50.f;
	target = sf::Vector2f(1100, 300);
	moving = true;

}

void Angrybird::handleInput(float dt)
{
	
		

}

void Angrybird::update(float dt)
{
	
	
	

	if (getPosition().y + getSize().y >= window->getSize().y)
	{
		setPosition(getPosition().x, window->getSize().y - getSize().y);
		stepVelocity = (-stepVelocity) / 1.2f;
	}

	if (getPosition().x + getSize().x >= window->getSize().x)
	{
		setPosition(window->getSize().x - getSize().x, getPosition().y);
	
	}

	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
	}

	if (getPosition().y < 0)
	{
		setPosition(getPosition().y, 0);
	}
}

Angrybird::~Angrybird()
{

}
