/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: VaultRoom.cpp is the VaultRoom class implementation file
*********************************************************************/	
#include <iostream>

#include "Room.hpp"
#include "VaultRoom.hpp"

VaultRoom::VaultRoom(std::string roomName) : Room()
{
	this->roomName = roomName;
}

VaultRoom::~VaultRoom() {}

void VaultRoom::entranceText()
{
	std::cout << "You've arrived at the " << roomName << "!" << std::endl;
	std::cout << "You need 3 matching gems to open the vault!" << std::endl;
}


