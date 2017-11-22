#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}

void Board::DrawBorder(Color c)
{
	int x, y;

	for (int j = 0; j < height; j++)
	{
		x = 0;
		Location loc = { x,j };
		DrawCell(loc, c);
	}
	for (int i = 0; i < width; i++)
	{
		y = 0;
		Location loc = { i,y };
		DrawCell(loc, c);
	}
	for (int j = 0; j < height; j++)
	{
		x = width -1;
		Location loc = { x,j };
		DrawCell(loc, c);
	}
	for (int i = 0; i < width; i++)
	{
		y = height -1;
		Location loc = { i,y };
		DrawCell(loc, c);
	}
}

int Board::GetBoardWidth() const
{
	return width;
}

int Board::GetBoardHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location & loc) const
{
	return loc.x >=1 && loc.x < width-1 &&
		loc.y >=1 && loc.y < height-1;
}
