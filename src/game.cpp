#include "game.h"

#include "raylib.h"
#include <cassert>

void Game::init() {
	eManager.addEntity<Jinx>();
	
	assert(eManager.mEntities.size() == 1);
	
	//mCamera.target = { 
	//	eManager.mEntities[0]->entityCam.mTarget.x,
	//	eManager.mEntities[0]->entityCam.mTarget.y
	//};
	//mCamera.offset = { screenWidth/2.0f, screenHeight/2.0f };
	//mCamera.rotation = 0.0f;
	//mCamera.zoom = 1.0f;
}

void Game::update() {
	eManager.updateEntities();
	//mCamera.target = {
	//	eManager.mEntities[0]->entityCam.mTarget.x,
	//	eManager.mEntities[0]->entityCam.mTarget.y
	//};
}

void Game::draw() {
	//BeginMode2D(mCamera);
		eManager.drawEntities();
	//EndMode2D();
}

Game::~Game() {
	//
}