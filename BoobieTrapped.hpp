/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: BoobieTrapped.hpp is the BoobieTrapped class specification file
*********************************************************************/
#ifndef BOOBIETRAPPED_HPP
#define BOOBIETRAPPED_HPP

#include <string>
#include <vector>

class BoobieTrapped : public Room
{
	public:
	BoobieTrapped(std::string);
	~BoobieTrapped();
	void entranceText();
	int numLostTurns();
}; 

#endif



