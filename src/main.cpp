#include "raylib.h"

#include "resource_dir.h"
#include "utils.h"
#include "entity.h"

int main() {
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(screenWidth, screenHeight, "Arcane: Jinx's arc");
	SearchAndSetResourceDir("resource");

	EntityManager eManager;
	eManager.addEntity<Jinx>();

	SetTargetFPS(60);

	while (true) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("This is Jinx's arc", 200, 200, 20, DARKPURPLE);

		eManager.updateEntities();
		eManager.drawEntities();

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