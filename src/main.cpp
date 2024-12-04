#include "raylib.h"

#include "resource_dir.h"
#include "utils.h"
#include "entity.h"


int main() {
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(screenWidth, screenHeight, "Arcane: Jinx's arc");
	SearchAndSetResourceDir("resource");

	Jinx jinx;
	jinx.init();

	SetTargetFPS(60);

	while (true) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("This is Jinx's arc", 200, 200, 20, DARKPURPLE);

		if (IsKeyDown(KEY_RIGHT)) jinx.mPosition.x += 2.0f;
		if (IsKeyDown(KEY_LEFT)) jinx.mPosition.x -= 2.0f;
		if (IsKeyDown(KEY_UP)) jinx.mPosition.y -= 2.0f;
		if (IsKeyDown(KEY_DOWN)) jinx.mPosition.y += 2.0f;

		DrawTexture(jinx.mTexture, jinx.mPosition.x, jinx.mPosition.y, WHITE);
		EndDrawing();

		if (WindowShouldClose()) {
			if (!IsKeyDown(KEY_ESCAPE)) {
				break;
			}
		}
	}

	UnloadTexture(jinx.mTexture);
	CloseWindow();
	return 0;
}