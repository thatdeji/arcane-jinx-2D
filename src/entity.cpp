#include "raylib.h"

#include "entity.h"
#include "utils.h"

Jinx::Jinx() {
	std::cout << "Jinx created automatically" << std::endl;
}

Jinx::~Jinx() {
	std::cout << "Jinx destroyed automatically" << std::endl;
	UnloadTexture(mTexture);
}

void Jinx::init() {
	mTexture = LoadTexture("JINXcc.png");
	mPosition = { (float)screenWidth / 3, (float)screenHeight / 2 };
}

void Jinx::update() {
	if (IsKeyDown(KEY_RIGHT)) mPosition.x += 2.0f;
	if (IsKeyDown(KEY_LEFT)) mPosition.x -= 2.0f;
	if (IsKeyDown(KEY_UP)) mPosition.y -= 2.0f;
	if (IsKeyDown(KEY_DOWN)) mPosition.y += 2.0f;
}

void Jinx::draw() {
	DrawTexture(mTexture, mPosition.x, mPosition.y, WHITE);
}

void Enforcer::init() {
	;
}

void Enforcer::update() {
	;
}

void Enforcer::draw() {
	;
}

void Isha::init() {
	;
}

void Isha::update() {
	;
}

void Isha::draw() {
	;
}