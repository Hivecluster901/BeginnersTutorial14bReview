#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Colors.h"
#include <assert.h>

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell( const Location &loc, Color c);
	void DrawBoundary();
	int GetGridWidth() const;
	int GetGridHeight() const;
	int GetStartX() const;
	int GetStartY() const;
	int GetDimension() const;
	bool IsWithinBoard(const Location& loc) const;
private:
	static constexpr int startX = 3;
	static constexpr int startY = 2;
	static constexpr int dimension = 20;
	static constexpr int boundaryThickness = 10;
	static constexpr int width = 33;
	static constexpr int height = 25;
	static constexpr int padding = 1;
	static constexpr Color boundaryColor = Colors::Blue;
	Graphics& gfx;
};