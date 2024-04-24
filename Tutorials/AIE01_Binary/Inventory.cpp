#include "Inventory.h"

#include <iostream>

#include "Weapons.h"

Inventory::Inventory()
	: m_contents{ 0x43 }
{
}

Inventory::Inventory(const uint8_t _defaultContents)
	: m_contents{ _defaultContents }
{
}

void Inventory::AddWeapon(const uint8_t _weapon)
{
	m_contents |= _weapon;
}

void Inventory::ToggleWeapon(const uint8_t _weapon)
{
	m_contents ^= _weapon;
}
void Inventory::Print() const
{
	std::cout << "Fists | ";

	if ((m_contents & Chainsaw) == Chainsaw)
		std::cout << "chainsaw | ";

	if ((m_contents & Pistol) == Pistol)
		std::cout << "Pistol | ";

	if ((m_contents & Shotgun) == Shotgun)
		std::cout << "Shotgun | ";

	if ((m_contents & SuperShotgun) == SuperShotgun)
		std::cout << "SuperShotgun | ";

	if ((m_contents & ChainGun) == ChainGun)
		std::cout << "ChainGun | ";

	if ((m_contents & RocketLauncher) == RocketLauncher)
		std::cout << "RocketLauncher | ";

	if ((m_contents & PlasmaGun) == PlasmaGun)
		std::cout << "PlasmaGun | ";

	if ((m_contents & Bfg9000) == Bfg9000)
		std::cout << "Bfg9000 | ";



}

void Inventory::SmartPrint() const
{
	std::cout << WEAPON_NAMES[0] << " | ";

	for(int i = 1; i < WEAPONS_MAX; ++i)
	{
		const int mask = 0x01 << (i - 1);
		if((m_contents & mask) == mask)
		{
			std::cout << WEAPON_NAMES[i] << " | ";
		}
	}
}


