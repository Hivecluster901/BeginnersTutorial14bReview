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
#include "Board.h"
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
    :
    wnd(wnd),
    gfx(wnd),
    rng(rd()),
    brd(gfx),
    snek({ 9,5 }),
    goal(brd, rng)
    
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
    brd.DrawBoundary();
    if (!isGameOver)
    {
        if (wnd.kbd.KeyIsPressed(VK_RIGHT))
        {
            delta_loc = { 1 , 0 };
        }
        if (wnd.kbd.KeyIsPressed(VK_LEFT))
        {
            delta_loc = { -1 , 0 };
        }
        if (wnd.kbd.KeyIsPressed(VK_UP))
        {
            delta_loc = { 0 , -1 };
        }
        if (wnd.kbd.KeyIsPressed(VK_DOWN))
        {
            delta_loc = { 0 , 1 };
        }
        snekMoveCounter++;
        if (snekMoveCounter >= snekMovePeriod)
        {
            snekMoveCounter = 0;
            
            if (wnd.kbd.KeyIsPressed(VK_CONTROL))
            {
                snek.Grow();
            }
            snek.MoveBy(delta_loc);
        }
        Location next = snek.GetNextHeadLocation(delta_loc);
        if (!brd.IsWithinBoard(next) || snek.IsInTileExceptEnd(next))
        {
            isGameOver = true;
        }
        
    }
}

void Game::ComposeFrame()
{
    snek.Draw(brd);
    goal.Draw(gfx,brd);
    if (isGameOver)
    {
        SpriteCodex::DrawGameOver(350, 250, gfx);
    }
}