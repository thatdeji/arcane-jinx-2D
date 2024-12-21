#include "raylib.h"

#include "entity.h"
#include "utils.h"
#include <iostream>

Jinx::Jinx() {
	std::cout << "Jinx created automatically" << std::endl;
}

Jinx::~Jinx() {
	std::cout << "Jinx destroyed automatically" << std::endl;
	UnloadTexture(mTexture);
}

void Jinx::init() {
	mTexture = LoadTexture("JINXc.png");
	mPosition = { 200.0f, 1005.0f };
	mFrameRec = { 0.0f, 0.0f, (float)mTexture.width / 6, (float)mTexture.height / 2 };
	mFramesCount = 1;
	entityCam.mTarget = { mPosition.x + 300.0f, mPosition.y };
	mCurrState = State::WALKING;
	mCurrDir = Direction::RIGHT;
	mPrevDir = Direction::RIGHT;
}

void Jinx::update() {
	if (IsKeyPressed(KEY_RIGHT)) {
		;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		mPosition.x += 10.0f;

		if (mCurrState != State::RUNNING) {
			mCurrState = State::RUNNING;
			mFrameRec.x = 0.0f;
			mFrameRec.y = mTexture.height / 2.0f;
			mFramesCount = 6;
			mCurrFrame = 0;
		}

		entityCam.mTarget.x += entityCam.mPanSpeed.x;
		if (entityCam.mTarget.x > mPosition.x + 300.0f) {
			entityCam.mTarget.x = mPosition.x + 300.0f;
		}

		entityCam.mTarget = { entityCam.mTarget.x, mPosition.y };

		mFrameRec.width = (mFrameRec.width < 0 ? mFrameRec.width * -1.0f : mFrameRec.width);
	}
	if (IsKeyDown(KEY_LEFT)) {
		mPosition.x -= 10.0f;

		if (mCurrState != State::RUNNING) {
			mCurrState = State::RUNNING;
			mFrameRec.x = 0.0f;
			mFrameRec.y = mTexture.height / 2.0f;
			mFramesCount = 6;
			mCurrFrame = 0;
		}

		entityCam.mTarget.x -= entityCam.mPanSpeed.x;
		if (entityCam.mTarget.x < mPosition.x - 70.0f) {
			entityCam.mTarget.x = mPosition.x - 70.0f;
		}

		entityCam.mTarget = { entityCam.mTarget.x, mPosition.y };

		mFrameRec.width = (mFrameRec.width < 0 ? mFrameRec.width : mFrameRec.width * -1.0f);
	}
	if (IsKeyDown(KEY_DOWN)) {
		mPosition.y += 10.0f;
	}
	if (IsKeyDown(KEY_UP)) {
		mPosition.y -= 10.0f;
	}
	if (IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT) && IsKeyUp(KEY_UP) && IsKeyUp(KEY_DOWN)){
		// Standing stance
		if (mCurrState != State::STANDING) {
			mCurrState = State::STANDING;
			mFrameRec.x = 0.0f;
			mFrameRec.y = 0.0f;
			mFramesCount = 1;
			mCurrFrame = 0;
		}

		return;
	}


	mFramesCounter++;
	if (mFramesCounter >= (60 / mFramesSpeed)) {
		mFramesCounter = 0;
		mCurrFrame++;

		if (mCurrFrame > (mFramesCount - 1)) mCurrFrame = 0;
		mFrameRec.x = (float)mCurrFrame * (float)mTexture.width / mFramesCount;
	}
}

void Jinx::draw() {
	DrawTextureRec(mTexture, mFrameRec, mPosition, WHITE);
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