#pragma once

#include "entity.h"
#include <memory>

constexpr int screenWidth = 1200;
constexpr int screenHeight = 600;

struct EntityManager {
	std::vector<std::unique_ptr<Entity>> mEntities;

	template <typename T>
	void addEntity() {
		T* c(new T());
		std::unique_ptr<Entity> entityPtr{ c };
		mEntities.emplace_back(std::move(entityPtr));
		c->init();
	}

	void updateEntities() {
		for (auto& e : mEntities) e->update();
	}

	void drawEntities() {
		for (auto& e : mEntities) e->draw();
	}
};