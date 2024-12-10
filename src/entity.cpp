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
	mTexture = LoadTexture("JINXc.png");
	mPosition = { (float)screenWidth / 3, (float)screenHeight / 2 };
	mFrameRec = { 0.0f, 0.0f, (float)mTexture.width / 6, (float)mTexture.height / 2 };
	mCurrentState = State::WALKING;
}

void Jinx::update() {
	if (IsKeyDown(KEY_RIGHT)) {
		mPosition.x += 10.0f;
		if (mCurrentState != State::RUNNING) {
			mCurrentState = State::RUNNING;
			mFrameRec.x = 0.0f;
			mFrameRec.y = mTexture.height / 2.0f;
			mFrameRec.width = (mFrameRec.width < 0 ? mFrameRec.width * -1.0f : mFrameRec.width);
			mFramesCount = 6;
			mCurrentFrame = 0;
		}

	} else if (IsKeyDown(KEY_LEFT)) {
		mPosition.x -= 10.0f;
		if (mCurrentState != State::RUNNING) {
			mCurrentState = State::RUNNING;
			mFrameRec.x = 0.0f;
			mFrameRec.y = mTexture.height / 2.0f;
			mFrameRec.width = (mFrameRec.width < 0 ? mFrameRec.width : mFrameRec.width * -1.0f);
			mFramesCount = 6;
			mCurrentFrame = 0;
		}
	}
	else {
		// Standing stance
		if (mCurrentState != State::WALKING) {
			mCurrentState = State::WALKING;
			mFrameRec.x = 0.0f;
			mFrameRec.y = 0.0f;
			mFramesCount = 1;
			mCurrentFrame = 0;
		}
		 
		 return;
	}

	//if (IsKeyDown(KEY_UP)) mPosition.y -= 2.0f;
	//if (IsKeyDown(KEY_DOWN)) mPosition.y += 2.0f;
	mFramesCounter++;
	if (mFramesCounter >= (60 / mFramesSpeed)) {
		mFramesCounter = 0;
		mCurrentFrame++;

		if (mCurrentFrame > (mFramesCount - 1)) mCurrentFrame = 0;
		mFrameRec.x = (float)mCurrentFrame * (float)mTexture.width / mFramesCount;
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