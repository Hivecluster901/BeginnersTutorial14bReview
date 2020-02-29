#pragma once

#include "Location.h"
#include "Colors.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include <random>

class Goal
{
public:
	Goal(const Board& brd, std::mt19937& rng, const Snake& snake);
	void Respawn(const Board& brd, std::mt19937& rng, const Snake& snake);
	void Draw(Board& brd) const;
	const Location& GetLocation() const;
private:
	Location loc;
	Color goalColor = Colors::Red;
};