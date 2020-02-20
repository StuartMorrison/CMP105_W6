#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include <iostream>



class Angrybird :
	public GameObject
{
public:

	sf::RenderWindow* window;
	sf::Vector2f startPos;
	sf::Vector2f endPos;
	sf::Vector2f direction;
	sf::Vector2f stepVelocity;
	sf::Vector2f gravity;
	sf::Vector2f launchD, launchNormal;
	float launchM;
	bool drag;
	float speed;



	Angrybird();
	void handleInput(float dt);
	void update(float dt);
	void setWindu(sf::RenderWindow* hwnd) { window = hwnd; };
	~Angrybird();

};

