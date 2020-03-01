#include "Obstacle.h"

void Obstacle::Init(const Board& brd, std::mt19937& rng, const Snake& snake, const Goal& goal, const Obstacle obs[], int numObstacles)
{
	std::uniform_int_distribution<int> xDist(brd.GetStartX(), brd.GetStartX() + brd.GetGridWidth());
	std::uniform_int_distribution<int> yDist(brd.GetStartY(), brd.GetStartY() + brd.GetGridHeight());

	do
	{
		loc = { xDist(rng), yDist(rng) };
	} while (snake.IsInTile(loc) || (goal.GetLocation() == loc ) || CheckLoc(obs, numObstacles));
}

void Obstacle::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

bool Obstacle::CheckLoc(const Obstacle obs[], int numObstacles)
{
	
	for (int i = 0; i < numObstacles; i++)
	{
		if (loc == obs[i].GetLocation())
		{
			return true;
		}
	}
	return false;
}

const Location& Obstacle::GetLocation() const
{
	return loc;
}
