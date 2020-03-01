#pragma once

#include "Location.h"
#include "Colors.h"
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include <random>

class Obstacle {

public:
	void Init( const Board& brd, std::mt19937& rng, const Snake& snake, const Goal& goal , const Obstacle obs[], int numObstacles);
	void Draw(Board& brd) const;
	bool CheckLoc( const Obstacle obs[], int numObstacles);
	const Location& GetLocation() const;

private:
	Location loc;
	Color c = Colors::Gray;
};
