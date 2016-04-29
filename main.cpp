/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: This file contains the main function to run a text-based
** fantasy game where the user is trying to open the vault in the 
** abandoned mansion before someone else gets the fortune.
*********************************************************************/	
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "GameWorld.hpp"
#include "GameSetUp.hpp"
#include "moveRooms.hpp"

int main()
{
	srand(time(NULL));

	GameWorld game; // Declare instance of GameWorld class
	gameSetUp(game); // Call gameSetUp function which initializes game settings

	do{         // do-while loops until the game ends either by the player winning or running out of turns

		std::cout << "You now have " << game.getRemainingTurns() << " turns remaining to get the vault open!\n" << std::endl;
		Room *temp = game.getCurrentRoom();
		temp->entranceText();
		
		bool endOfTurn = false;
		int selection;	

		do  // do-while loops until the end of a turn is reached
		{
			if (temp->getBoobieTrapped()) // Player's turn is immediately over if they enter a boobie trapped room
			{
				game.decrementTurns();
				if (!game.inPlay())
				{
					break;
				}
				else
				{
					std::cout << "\nYou now have " << game.getRemainingTurns() << " turns remaining to get the vault open!\n" << std::endl;
					std::cout << "Make a selection to move to another room" << std::endl;
					game.setCurrentRoom(moveRooms(game));
					endOfTurn = true;
					break;
				}
			}
			std::cout << "\n\nWould you like to: " << std::endl;
			std::cout << "\t1. View the object(s) in the room" << std::endl;
			std::cout << "\t2. View the object(s) you have with you" << std::endl;
			std::cout << "\t3. Pick up an object" << std::endl;
			std::cout << "\t4. Put down an object" << std::endl;
			std::cout << "\t5. Move to another room" << std::endl;
			std::cin >> selection;

			if (selection < 1 || selection > 5)
			{
				std::cout << "\nInvalid selection. Please make a valid selection between 1-5." << std::endl;
				std::cin >> selection;
			}

			switch(selection)
			{
				case 1:
					temp->viewObjects(); // View objects in current room
					break;
				case 2:
					game.viewItems(); // View objects the player has
					break;
				case 3:
					if (temp->objectInRoom()) // If there are object(s) in the room
					{
						if (game.canAddObject()) // If the player has room for more objects
						{
							std::cout << "\nEnter the item number you would like to pick up: " << std::endl;
							temp->viewObjects();
							int val;
							std::cin >> val;
							while (val < 1 || val > temp->numObjects())
							{
								std::cout << "\nInvald choice. Please make a valid selection." << std::endl;
								std::cin >> val;

							}	
							game.addObject(temp->removeObject(val)); // Add the object to the player's inventory, remove from the room
						}						
					}
					else 
					{
						std::cout << "\nInvalid choice. No items in this room." << std::endl;
					}
					break;
				case 4:
					if (game.objectOnHand())
					{
						std::cout << "\nEnter the item number you would like to put down: " << std::endl;
						game.viewItems();
						int val;
						std::cin >> val;
						while (val < 1 || val > game.numObjects())
						{
							std::cout << "\nInvald choice. Please make a valid selection." << std::endl;
							std::cin >> val;
						}	
						temp->addObject(game.getObject(val));
						game.removeObject(val);
					}
					else
					{
						std::cout << "\nInvalid choice. You don't have any items to put down." << std::endl;
					}
					break;
				case 5:
					game.setCurrentRoom(moveRooms(game));
					game.endOfTurn();
					endOfTurn = true;
					break;
			}
		} while(!endOfTurn);

		if (!game.playerWins() && game.inPlay())
		{
			std::cout << "\n\nYou've reached the end of the turn by changing rooms." << std::endl;
		}

	} while (game.inPlay() && !game.playerWins());

	if (game.playerWins())
	{
		std::cout << "\nCongratulations, you've opened the vault and obtained the fortune! You win!" << std::endl;
	}
	else if (!game.inPlay())
	{
		std::cout << "\nSorry, you've lost the game." << std::endl;
	}	
	
	return 0;
}


