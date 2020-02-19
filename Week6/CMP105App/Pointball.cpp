#include "Pointball.h"

Pointball::Pointball()
{
	acceleration = 500.f;
}

void Pointball::update(float dt)
{
	target = sf::Vector2f(input->getMouseX(), input->getMouseY());

	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity += (direction * acceleration) * dt;
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(target - getPosition()) < 2.f)
	{
		setPosition(target);
	}

}

Pointball::~Pointball()
{

}
