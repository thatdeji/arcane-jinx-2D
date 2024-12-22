#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "raylib.h"

struct EntityCam {
	Vector2 mPanSpeed = { 15.0f, 15.0f };
	Vector2 mTarget;
};

struct Entity {
	EntityCam entityCam;

	Texture mTexture;
	Vector2 mPosition;
	Vector2 mVelocity; // x = l-r velocity, y = up-down velocity
	Vector2 mAcceleration; // x = l-r acceleration, y = up-down acceleration

	Rectangle mFrameRec = { 0.0f, 0.0f, 0.0f, 0.0f };
	const size_t mFramesSpeed = 8;
	size_t mFramesCounter = 0;
	size_t mCurrFrame = 0;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	virtual ~Entity() = default;
};

struct Jinx : Entity {
	enum class State{
		STANDING,
		WALKING,
		RUNNING,
	};

	enum class Direction {
		LEFT,
		RIGHT,
	};
	
	Jinx();
	void init() override;
	void update() override;
	void draw() override;
	~Jinx();



	// Member variables
	size_t mFramesCount;
	size_t mSheetWidth;
	State mCurrState;
	Direction mCurrDir;
	Direction mPrevDir;
};

struct Enforcer : Entity {
	void init() override;
	void update() override;
	void draw() override;
};

struct Isha : Entity {
	void init() override;
	void update() override;
	void draw() override;
};