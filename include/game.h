#pragma once


#include "raylib.h"
#include "utils.h"

struct Game {
	//Camera2D mCamera;
	EntityManager eManager;

	float mPanVelocity{ 0.5f };

	void init();
	void update();
	void draw();

	~Game();
};