#pragma once

#include "raylib.h"

class platform {
public:
	Rectangle platformRectangleObject;

	void draw();
};

class fanPlatform {
public:
	Rectangle fanPlatformRectangleObject;

	void draw();
};