#pragma once

#include "raylib.h"

struct Entity {
	Texture mTexture;
	Vector2 mPosition;

	const int mFramesSpeed = 8;
	int mFramesCounter = 0;

	Rectangle frmeRec = { 0.0f, 0.0f, 0.0f, 0.0f };

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

struct Jinx : Entity {
	void init() override;
	void update() override;
	void draw() override;
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