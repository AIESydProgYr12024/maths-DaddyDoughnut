#include <iostream>

#include "Inventory.h"
#include "Weapons.h"
int main()
{
	Inventory inventory = Inventory();

	inventory.Print();
	std::cin.get();

	inventory.AddWeapon(RocketLauncher);
	inventory.AddWeapon(Pistol);
	inventory.AddWeapon(Chainsaw);

	inventory.Print();
	std::cin.get();

	inventory.ToggleWeapon(Pistol);

	inventory.Print();
	std::cin.get();

	inventory.ToggleWeapon(Pistol);

	inventory.Print();
	std::cin.get();

	inventory = Inventory();
	inventory.AddWeapon(Bfg9000);
	inventory.AddWeapon(RocketLauncher);
	inventory.AddWeapon(SuperShotgun);
	inventory.AddWeapon(ChainGun);

	inventory.SmartPrint();
	std::cin.get();

	return 0;
}