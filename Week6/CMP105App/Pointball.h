#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Pointball :
	public GameObject
{
public:

	float acceleration;
	sf::Vector2f target;
	sf::Vector2f direction;
	sf::Vector2f velocity;
	sf::RenderWindow* window;

	Pointball();
	void update(float dt);
	void setWindu(sf::RenderWindow* hwnd) { window = hwnd; };
	~Pointball();


};

