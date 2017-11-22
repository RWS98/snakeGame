#include "Fruit.h"

Fruit::Fruit(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	Respawn(rng, brd, snake);
}

void Fruit::Respawn(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	std::uniform_int_distribution<int> xDist(1, brd.GetBoardWidth() - 2);
	std::uniform_int_distribution<int> yDist(1, brd.GetBoardHeight() - 2);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc));

	loc = newLoc;
}

void Fruit::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location & Fruit::GetLocation() const
{
	return loc;
}
