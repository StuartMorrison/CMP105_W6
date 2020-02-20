#include "Angrybird.h"

Angrybird::Angrybird()
{

	speed = 50.f;
	//target = sf::Vector2f(1100, 300);
	gravity = sf::Vector2f(0.f, 9.8f) * 50.f;
	drag = false;

	stepVelocity = sf::Vector2f(0.f, 0.f);
	launchNormal = sf::Vector2f(0.f, 0.f);

}

void Angrybird::handleInput(float dt)
{
	
	if (input->isMouseRDown())
	{
		if (!drag)
		{
			startPos.x = input->getMouseX();
			startPos.y = input->getMouseY();
			drag = true;
		}
	}
	else if(input->isMouseRDown() == false && drag == true)
	{
		endPos.x = input->getMouseX();
		endPos.y = input->getMouseY();
		launchD = startPos - endPos;
		launchM = Vector::magnitude(launchD);
		launchNormal = launchD / launchM;
		stepVelocity += (launchD * launchM) * dt;
		drag = false;
	}



	

}

void Angrybird::update(float dt)
{
	
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; 
	stepVelocity += gravity * dt; 
	setPosition(getPosition() + pos);
	

	if (getPosition().y + getSize().y >= window->getSize().y)
	{
		setPosition(getPosition().x, window->getSize().y - getSize().y);
		stepVelocity.y = (-stepVelocity.y) / 2.0f;
	}

	if (getPosition().x + getSize().x >= window->getSize().x)
	{
		setPosition(window->getSize().x - getSize().x, getPosition().y);
		stepVelocity.x = (-stepVelocity.x) / 2.0f;
	}

	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		stepVelocity.x = (-stepVelocity.x) / 2.0f;
	}

	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
		stepVelocity.y = (-stepVelocity.y) / 2.0f;
	}
}

Angrybird::~Angrybird()
{

}
