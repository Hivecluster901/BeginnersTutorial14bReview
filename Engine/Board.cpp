#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell( const Location& loc, Color c)
{
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}

void Board::DrawBoundary()
{
	for(int x = startX - 1; x <= startX + width + 1; x++ )
	{ 
		gfx.DrawRectDim(x * dimension, (startY - 1) * dimension, dimension, dimension, boundaryColor);
		gfx.DrawRectDim(x * dimension, (startY + height + 1) * dimension, dimension, dimension, boundaryColor);
	}
	for (int y = startY - 1; y <= startY + height + 1; y++)
	{
		gfx.DrawRectDim((startX - 1) * dimension, y * dimension, dimension, dimension, boundaryColor);
		gfx.DrawRectDim((startX + width + 1) * dimension, y * dimension, dimension, dimension, boundaryColor);
	}
}


int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

int Board::GetStartX() const
{
	return startX;
}

int Board::GetStartY() const
{
	return startY;
}

int Board::GetDimension() const
{
	return dimension;
}

bool Board::IsWithinBoard(const Location& loc) const
{
	return loc.x >= startX && loc.y >= startY && loc.x <= startX + width && loc.y <= startY + height;
}
