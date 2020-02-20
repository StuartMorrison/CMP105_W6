#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include <iostream>



class Angrybird :
	public GameObject
{
public:

	sf::RenderWindow* window;
	
	float acceleration;
	sf::Vector2f direction;
	bool moving;
	bool drag;



	Angrybird();
	void handleInput(float dt);
	void update(float dt);
	void setWindu(sf::RenderWindow* hwnd) { window = hwnd; };
	~Angrybird();

};

