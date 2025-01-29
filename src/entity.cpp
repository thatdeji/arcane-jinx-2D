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
	mTexture = LoadTexture("JINX.png");
	mPosition = { 0.0f, 0.0f };
	mFrameRec = { 0.0f, 0.0f, (float)mTexture.width / 2, (float)mTexture.height };
	mFramesCount = 2;
	// entityCam.mTarget = { mPosition.x + 300.0f, mPosition.y };
	mCurrState = State::STANDING;
}

void Jinx::update() {
	if (IsKeyDown(KEY_RIGHT)) {
		mPosition.x += 10.0f;
	
		//if (mCurrState != State::RUNNING) {
		//	mCurrState = State::RUNNING;
		//	mFrameRec.x = 0.0f;
		//	mFrameRec.y = mTexture.height / 2.0f;
		//	mFramesCount = 6;
		//	mSheetWidth = mTexture.width;
		//	mCurrFrame = 0;
		//}
		//
		//entityCam.mTarget.x += entityCam.mPanSpeed.x;
		//if (entityCam.mTarget.x > mPosition.x + 300.0f) {
		//	entityCam.mTarget.x = mPosition.x + 300.0f;
		//}
		//
		//entityCam.mTarget = { entityCam.mTarget.x, mPosition.y };
		//
		//mFrameRec.width = (mFrameRec.width < 0 ? mFrameRec.width * -1.0f : mFrameRec.width);
	}
	if (IsKeyDown(KEY_LEFT)) {
		mPosition.x -= 10.0f;

		//if (mCurrState != State::RUNNING) {
		//	mCurrState = State::RUNNING;
		//	mFrameRec.x = 0.0f;
		//	mFrameRec.y = mTexture.height / 2.0f;
		//	mFramesCount = 6;
		//	mSheetWidth = mTexture.width;
		//	mCurrFrame = 0;
		//}
		//
		//entityCam.mTarget.x -= entityCam.mPanSpeed.x;
		//if (entityCam.mTarget.x < mPosition.x - 123.0f) {
		//	entityCam.mTarget.x = mPosition.x - 123.0f;
		//}
		//
		//entityCam.mTarget = { entityCam.mTarget.x, mPosition.y };
		//
		//mFrameRec.width = (mFrameRec.width < 0 ? mFrameRec.width : mFrameRec.width * -1.0f);
	}
	if (IsKeyDown(KEY_DOWN))
		mPosition.y += 10.0f;

	if (IsKeyDown(KEY_UP))
		mPosition.y -= 10.0f;
	
	//if (IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT) && IsKeyUp(KEY_UP) && IsKeyUp(KEY_DOWN)){
	//	if (mCurrState != State::STANDING) {
	//		mCurrState = State::STANDING;
	//		mFrameRec.x = 0.0f;
	//		mFrameRec.y = 0.0f;
	//		mFramesCount = 1;
	//		mCurrFrame = 0;
	//	}
	//
	//	return;
	//}


	mFramesCounter++;
	if (mFramesCounter >= (60 / mFramesSpeed)) {
		mFramesCounter = 0;
		mCurrFrame++;

		if (mCurrFrame > (mFramesCount - 1)) mCurrFrame = 0;
		mFrameRec.x = (float)mCurrFrame * (float)mFrameRec.width;
	}
}

void Jinx::draw() {
	Vector2 origin = { (float)mFrameRec.width, (float)mFrameRec.height };
	Rectangle mDestRec = { screenWidth / 2.0f, screenHeight / 2.0f, mFrameRec.width * 4.0f, mFrameRec.height * 4.0f };
	DrawTexturePro(mTexture, mFrameRec, mDestRec, origin, 0.0f, WHITE);
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