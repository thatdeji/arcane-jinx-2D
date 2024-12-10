#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "raylib.h"

struct Entity {
	Texture mTexture;
	Vector2 mPosition;

	Rectangle mFrameRec = { 0.0f, 0.0f, 0.0f, 0.0f };
	const size_t mFramesSpeed = 8;
	size_t mFramesCounter = 0;
	size_t mCurrentFrame = 0;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	virtual ~Entity() = default;
};

struct Jinx : Entity {
	enum class State{
		WALKING,
		RUNNING,
	};
	
	Jinx();
	void init() override;
	void update() override;
	void draw() override;
	~Jinx();

	// Member variables
	size_t mFramesCount = 1;
	State mCurrentState = State::WALKING;
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