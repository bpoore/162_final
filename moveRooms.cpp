/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: moveRooms.cpp is the moveRooms class implementation file
** The moveRooms function allows the player to change from the room they are 
** currently in to a new room based upon the options available to them.
** Parameters: The function has an input parameter of a GameWorld instance 
** passed by reference. The function returns a pointer to Room object.
*********************************************************************/	
#include <iostream>

#include "moveRooms.hpp"

Room* moveRooms(GameWorld &game)
{
	// Determine the directions the player could possibly move and let them know
	std::cout << "You can move: " << std::endl;	
	if (game.getCurrentRoom()->getNorth())
	{
		std::cout << "North" << std::endl;
	}
	if (game.getCurrentRoom()->getSouth())
	{
		std::cout << "South" << std::endl;
	}
	if (game.getCurrentRoom()->getEast())
	{
		std::cout << "East" << std::endl;
	}
	if (game.getCurrentRoom()->getWest())
	{
		std::cout << "West" << std::endl;
	}
	
	// Prompt the player to enter the direction they would like to go	
	std::cout << "Which direction would you like to move?" << std::endl;
	std::cout << "n = North, s = South, e = East, w = West" << std::endl;
	char direction;
	std::cin >> direction;	

	bool goodDirection = false;

	do // do-while loop continues until the player makes a valid direction selection
	{
		if (direction == 'n' && game.getCurrentRoom()->getNorth())
		{
			game.setCurrentRoom(game.getCurrentRoom()->getNorth());
			goodDirection = true;
		}
		else if (direction == 's' && game.getCurrentRoom()->getSouth())
		{
			game.setCurrentRoom(game.getCurrentRoom()->getSouth());
			goodDirection = true;
		}
		else if (direction == 'e' && game.getCurrentRoom()->getEast())
		{
			game.setCurrentRoom(game.getCurrentRoom()->getEast());
			goodDirection = true;
		}
		else if (direction == 'w' && game.getCurrentRoom()->getWest())
		{
			game.setCurrentRoom(game.getCurrentRoom()->getWest());
			goodDirection = true;
		}
		else
		{
			std::cout << "You can't go that way. Please enter a valid direction." << std::endl;
			std::cin >> direction;
		}
	} while (!goodDirection);

	return (game.getCurrentRoom());
}