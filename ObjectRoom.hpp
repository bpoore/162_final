/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: ObjectRoom.hpp is the ObjectRoom class specification file
*********************************************************************/
#ifndef OBJECTROOM_HPP
#define OBJECTROOM_HPP

#include <string>
#include <vector>

class ObjectRoom : public Room
{
	protected:
	std::string object;
	
	public:
	ObjectRoom(std::string, std::string);
	~ObjectRoom();
	void entranceText();
};
#endif



