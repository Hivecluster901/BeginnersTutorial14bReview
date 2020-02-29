#include "Goal.h"

Goal::Goal(const Board& brd, std::mt19937& rng, const Snake& snake)
{
	Respawn(brd, rng, snake);
}

void Goal::Respawn(const Board& brd, std::mt19937& rng, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(brd.GetStartX(), brd.GetStartX() + brd.GetGridWidth());
	std::uniform_int_distribution<int> yDist(brd.GetStartY(), brd.GetStartY() + brd.GetGridHeight());

	do
	{
		loc = { xDist(rng), yDist(rng) };
	} while (snake.IsInTile(loc));
}

void Goal::Draw(Board& brd) const
{
	brd.DrawCell(loc, goalColor);
}

const Location& Goal::GetLocation() const
{
	return loc;
}
