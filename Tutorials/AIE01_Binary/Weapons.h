#pragma once

#include <cstring>
#include <string>

using std::string;

constexpr int WEAPONS_MAX = 9;

enum EWeapons : uint8_t
{
	Fists = 0x00,
	Chainsaw = 0x01,
	Pistol = 0x01 << 1,
	Shotgun = 0x01 << 2,
	SuperShotgun = 0x01 << 3,
	ChainGun = 0x01 << 4,
	RocketLauncher = 0x01 << 5,
	PlasmaGun = 0x01 << 6,
	Bfg9000 = 0x01 << 7


};

inline EWeapons operator|(const EWeapons _a, const EWeapons _b)
{
	return static_cast<EWeapons>(static_cast<int>(_a) | static_cast<int>(_b));
}

inline EWeapons operator&(const EWeapons _a, const EWeapons _b)
{
	return static_cast<EWeapons>(static_cast<int>(_a) & static_cast<int>(_b));
}

inline const string WEAPON_NAMES[WEAPONS_MAX]
{
	"Fists",
	"Chainsaw",
	"Pistol",
	"Shotgun",
	"Super Shotgun",
	"Chain Gun",
	"Rocket Launcher",
	"Plasma Gun",
	"Bfg9000"
};