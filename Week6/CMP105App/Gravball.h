#pragma once
#include "Framework/GameObject.h"
class Gravball :
	public GameObject
{
public:

	float scale;
	int isJumping;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
	sf::RenderWindow* window;


	Gravball();
	void handleInput(float dt);
	void update(float dt);
	void setWindu(sf::RenderWindow* hwnd) { window = hwnd; };
	~Gravball();

};

