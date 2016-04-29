/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: ObjectsRoom.hpp is the ObjectsRoom class specification file
*********************************************************************/
#ifndef OBJECTSROOM_HPP
#define OBJECTSROOM_HPP

#include <string>
#include <vector>

class ObjectsRoom : public Room
{
	protected:
	std::string object1, object2;
	
	public:
	ObjectsRoom(std::string, std::string, std::string);
	~ObjectsRoom();
	void entranceText();
};
#endif


