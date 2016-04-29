/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: ObjectRoom.cpp is the ObjectRoom class implementation file
*********************************************************************/	
#include <iostream>

#include "Room.hpp"
#include "ObjectRoom.hpp"

ObjectRoom::ObjectRoom(std::string roomName, std::string object) : Room()
{
	this->roomName = roomName;
	this->object = object;
	this->roomType = "ObjectRoom";	
	objects.push_back(object);	
}

ObjectRoom::~ObjectRoom() {}

void ObjectRoom::entranceText()
{
	std::cout << "You're now in the " << roomName << "." << std::endl;
}
 
