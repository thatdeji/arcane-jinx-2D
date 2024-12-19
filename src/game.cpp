#include "game.h"

#include "raylib.h"
#include <cassert>

void Game::init() {
	mBackground.mTexture = LoadTexture("midgroundd.png");

	jinx.init();
	
	mCamera.target = { jinx.mPosition.x, jinx.mPosition.y};
	mCamera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
	mCamera.rotation = 0.0f;
	mCamera.zoom = 1.0f;
}

void Game::update() {
	jinx.update();
	eManager.updateEntities();
}

void Game::draw() {
	BeginMode2D(mCamera);
		DrawTextureEx(mBackground.mTexture, { 0.0f, -200.0f }, 0.0f, 1.0f, WHITE);
		eManager.drawEntities();
		jinx.draw();
	EndMode2D();
}

Game::~Game() {
	UnloadTexture(mBackground.mTexture);
}