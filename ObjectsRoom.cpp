/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: ObjectsRoom.cpp is the ObjectsRoom class implementation file
*********************************************************************/	
#include <iostream>

#include "Room.hpp"
#include "ObjectsRoom.hpp"

ObjectsRoom::ObjectsRoom(std::string roomName, std::string object1, std::string object2) : Room()
{
	this->roomName = roomName;
	this->object1 = object1;
	this->object2 = object2;
	this->roomType = "ObjectRoom";	
	objects.push_back(object1);	
	objects.push_back(object2);
}

ObjectsRoom::~ObjectsRoom() {}

void ObjectsRoom::entranceText()
{
	std::cout << "You're now in the " << roomName << "." << std::endl;
}
 
