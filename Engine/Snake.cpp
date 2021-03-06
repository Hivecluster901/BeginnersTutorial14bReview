#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);

}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody(nSegments);
		nSegments++;
	}
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l = segments[0].GetLocation();
	l.Add(delta_loc);
	return l;
}

bool Snake::IsInTileExceptEnd(const Location& loc) const
{
	for (int i = 0; i < nSegments - 1; i++)
	{
		if (segments[i].GetLocation() == loc)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile(const Location& loc) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == loc)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(int n )
{
	int g;
	if ((n - 1) % 4 == 3)
	{
		g = 100 + 70;
	}
	else
	{
		g = 100 + 70 * ((n - 1) % 4);
	}
	c = Colors::MakeRGB(0, g, 0);
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1); // x or y is one or negative one.
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
