/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: VaultRoom.hpp is the VaultRoom function specification file
*********************************************************************/
#ifndef VAULTROOM_HPP
#define VAULTROOM_HPP

#include <string>

class VaultRoom : public Room
{
	public:
	VaultRoom(std::string);
	~VaultRoom();
	void entranceText();
};

#endif
