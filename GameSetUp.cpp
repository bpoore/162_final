/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: GameSetUp.cpp is the GameSetUp function implementation file
*********************************************************************/	
#include <iostream>

#include "GameSetUp.hpp"

void gameSetUp(GameWorld &game)
{
	// Declare pointer to Room objects
	Room *entry = new ObjectsRoom("Entry", "Ruby", "Emerald");
	game.addRoom(entry);	

	Room *lounge = new BoobieTrapped("Lounge");
	game.addRoom(lounge);

	Room *study = new BoobieTrapped("Study");
	game.addRoom(study);

	Room *library = new ObjectsRoom("Library", "Shield", "Bag");
	game.addRoom(library);

	Room *dinning = new ObjectsRoom("Dinning", "Emerald", "Diamond");
	game.addRoom(dinning);

	Room *kitchen = new BoobieTrapped("Kitchen");
	game.addRoom(kitchen);

	Room *observatory = new ObjectsRoom("Observatory", "Emerald", "Ruby");
	game.addRoom(observatory);

	Room *pool = new BoobieTrapped("Pool");
	game.addRoom(pool);

	Room *billiards = new ObjectsRoom("Billiards", "Diamond", "Diamond");
	game.addRoom(billiards);  

	Room *vaultRoom = new VaultRoom("Vault");
	game.addRoom(vaultRoom);

	// Set the coordinate system for the mansion, updating connections from NULL to the appropriate Room pointer
	entry->setEast(lounge);
	entry->setWest(observatory);

	vaultRoom->setNorth(study);
	vaultRoom->setEast(pool);
	vaultRoom->setWest(kitchen);

	study->setSouth(vaultRoom);
	study->setEast(library);
	study->setWest(dinning);

	dinning->setEast(study);
	dinning->setSouth(kitchen);

	kitchen->setNorth(dinning);
	kitchen->setEast(vaultRoom);
	kitchen->setSouth(observatory);

	observatory->setNorth(kitchen);
	observatory->setEast(entry);
	observatory->setWest(library);

	lounge->setWest(entry);
	lounge->setEast(billiards);

	billiards->setNorth(pool);
	billiards->setWest(lounge);

	pool->setNorth(library);
	pool->setSouth(billiards);
	pool->setWest(vaultRoom);

	library->setSouth(pool);
	library->setEast(observatory);
	library->setWest(study);

	std::cout << "\n\n\n\nA wealthy man has died, leaving his fortune inside his abandoned mansion." << std::endl;
	std::cout << "If you are so brave as to try to obtain this fortune, you must find the vault " << std::endl;
	std::cout << "and determine how to open it! A turn is over when you move to a new room. Beware of traps!\n\n" << std::endl;
	std::cout << "Clues for success...." << std::endl;
	std::cout << "Until you find the bag, you can only hold two items at a time." << std::endl;
	std::cout << "After picking up the bag, you can hold 5 items at a time (including the bag itslef)." << std::endl;
	std::cout << "The bag is key because you must have 3 matching gems in order to open the vault." << std::endl;
	std::cout << "There are several traps along the way, it's to your benefit to find the shield for protection!\n\n" << std::endl;
	game.setCurrentRoom(entry);
}

