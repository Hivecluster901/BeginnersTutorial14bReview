#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell( const Location& loc, Color c)
{
	gfx.DrawRectDim(loc.x * (dimension) + padding, loc.y * dimension + padding , dimension - 2* padding, dimension -2 * padding, c);
}

void Board::DrawBoundary()
{
	for(int x = startX; x <= startX + width; x++ )
	{ 
		gfx.DrawRectDim(x * dimension, (startY - 1) * dimension + boundaryThickness, dimension, boundaryThickness, boundaryColor);
		gfx.DrawRectDim(x * dimension, (startY + height + 1) * dimension, dimension, boundaryThickness, boundaryColor);
	}
	gfx.DrawRectDim((startX-1) * dimension + boundaryThickness, (startY - 1) * dimension + boundaryThickness, boundaryThickness, boundaryThickness, boundaryColor);
	gfx.DrawRectDim((startX - 1) * dimension + boundaryThickness, (startY + height + 1) * dimension, boundaryThickness, boundaryThickness, boundaryColor);
	for (int y = startY; y <= startY + height ; y++)
	{
		gfx.DrawRectDim((startX - 1) * dimension + boundaryThickness, y * dimension, boundaryThickness, dimension, boundaryColor);
		gfx.DrawRectDim((startX + width + 1) * dimension, y * dimension, boundaryThickness, dimension, boundaryColor);
	}
	gfx.DrawRectDim((startX + width + 1) * dimension, (startY - 1) * dimension + boundaryThickness, boundaryThickness, boundaryThickness, boundaryColor);
	gfx.DrawRectDim((startX + width + 1)* dimension, (startY + height + 1) * dimension, boundaryThickness, boundaryThickness, boundaryColor);
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
