#include "Pointball.h"

Pointball::Pointball()
{
	speed = 100.f;
	acceleration = 50.f;
	target = sf::Vector2f(window->getSize().x - 50, window->getSize().y - 50);
}

void Pointball::update(float dt)
{

	direction = target = getPosition();
	direction = Vector::normalise(direction);
	velocity = (direction * speed);
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
	}

}

Pointball::~Pointball()
{

}
