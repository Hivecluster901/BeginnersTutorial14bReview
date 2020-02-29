#include "Goal.h"

Goal::Goal(const Board& brd, std::mt19937& rng)
{
	Respawn(brd, rng);
}

void Goal::Respawn(const Board& brd, std::mt19937& rng)
{
	std::uniform_int_distribution<int> xDist(brd.GetStartX(), brd.GetStartX() + brd.GetGridWidth());
	std::uniform_int_distribution<int> yDist(brd.GetStartY(), brd.GetStartY() + brd.GetGridHeight());

	loc = { xDist(rng), yDist(rng) };
}

void Goal::Draw(Graphics& gfx, const Board& brd) const
{
	gfx.DrawRectDim(loc.x * brd.GetDimension(), loc.y * brd.GetDimension(), brd.GetDimension(), brd.GetDimension(), goalColor);
}

const Location& Goal::GetLocation() const
{
	return loc;
}
