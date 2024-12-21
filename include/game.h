#pragma once


#include "raylib.h"
#include "utils.h"

struct Background {
	Texture mTexture;
};

struct Game {
	Background mBackground;
	Camera2D mCamera;
	EntityManager eManager;

	float mPanVelocity{ 0.5f };

	//float mBgScroll{ 0.0f };
	//float mMgScroll{ 0.0f };
	//float mBgScrollVelocity{ 1.0f };
	//float mMgScrollVelocity{ 0.0f };

	void init();
	void update();
	void draw();

	~Game();
};