#include "raylib.h"

#include "resource_dir.h"
#include "utils.h"
#include "entity.h"
#include "game.h"

int main() {
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(screenWidth, screenHeight, "Arcane: Jinx's arc");
	SearchAndSetResourceDir("resource");

	Game game;
	game.init();

	SetTargetFPS(60);

	while (true) {
		BeginDrawing();
			
			ClearBackground({ 13, 21, 24 });

			game.update();

			game.draw();

		EndDrawing();

		if (WindowShouldClose()) {
			if (!IsKeyDown(KEY_ESCAPE)) {
				break;
			}
		}
	}

	CloseWindow();
	return 0;
}