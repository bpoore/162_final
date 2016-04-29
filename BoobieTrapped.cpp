/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: BoobieTrapped.cpp is the BoobieTrapped class implementation file
*********************************************************************/	
#include <iostream>

#include "Room.hpp"
#include "BoobieTrapped.hpp"

BoobieTrapped::BoobieTrapped(std::string roomName) : Room()
{
	this->roomName = roomName;
	this->roomType = "BoobieTrapped";	
	boobieTrapped = true;
}

BoobieTrapped::~BoobieTrapped() {}

void BoobieTrapped::entranceText()
{
	std::cout << "You're now in the " << roomName << "." << std::endl;
	std::cout << "This room is " << roomType << "!!" << std::endl;
}

int BoobieTrapped::numLostTurns()
{
	int numLostTurns;
	numLostTurns = rand()%6 + 1;
	return numLostTurns;
}
 
