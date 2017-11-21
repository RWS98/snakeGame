/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::ComposeFrame()
{
	int x = 400;
	int y = 300;
	int r = 255;
	int g = 255;
	int b = 500;

	const bool upPressed = wnd.kbd.KeyIsPressed(VK_UP);
	const bool downPressed = wnd.kbd.KeyIsPressed(VK_DOWN);
	const bool leftPressed = wnd.kbd.KeyIsPressed(VK_LEFT);
	const bool rightPressed = wnd.kbd.KeyIsPressed(VK_RIGHT);
	const bool colorChange = wnd.kbd.KeyIsPressed(VK_CONTROL);
	const bool rectileChange = wnd.kbd.KeyIsPressed(VK_SHIFT);

	if (upPressed == true)
	{
		y = 100;
	}
	if (downPressed == true)
	{
		y = 500;
	}
	if (leftPressed == true)
	{
		x = 200;
	}
	if (rightPressed == true)
	{
		x = 600;
	}
	if (colorChange == true)
	{
		g = 0;
		b = 0;
	}
	
	if (rectileChange == true)
	{
		gfx.PutPixel(x + 5, y + 5, r, g, b);
		gfx.PutPixel(x + 4, y + 5, r, g, b);
		gfx.PutPixel(x + 5, y + 4, r, g, b);
		gfx.PutPixel(x - 5, y + 5, r, g, b);
		gfx.PutPixel(x - 4, y + 5, r, g, b);
		gfx.PutPixel(x - 5, y + 4, r, g, b);
		gfx.PutPixel(x + 5, y - 5, r, g, b);
		gfx.PutPixel(x + 4, y - 5, r, g, b);
		gfx.PutPixel(x + 5, y - 4, r, g, b);
		gfx.PutPixel(x - 5, y - 5, r, g, b);
		gfx.PutPixel(x - 4, y - 5, r, g, b);
		gfx.PutPixel(x - 5, y - 4, r, g, b);
	}
	else
	{
		gfx.PutPixel(x - 5, y, r, g, b);
		gfx.PutPixel(x - 4, y, r, g, b);
		gfx.PutPixel(x - 3, y, r, g, b);
		gfx.PutPixel(x + 3, y, r, g, b);
		gfx.PutPixel(x + 4, y, r, g, b);
		gfx.PutPixel(x + 5, y, r, g, b);
		gfx.PutPixel(x, y - 5, r, g, b);
		gfx.PutPixel(x, y - 4, r, g, b);
		gfx.PutPixel(x, y - 3, r, g, b);
		gfx.PutPixel(x, y + 3, r, g, b);
		gfx.PutPixel(x, y + 4, r, g, b);
		gfx.PutPixel(x, y + 5, r, g, b);
	}
}
