#pragma once

#include <cstdint>

class Inventory
{
public:
	Inventory();
	Inventory(uint8_t _defaultContents);

public:
	void AddWeapon(uint8_t _weapon);
	void ToggleWeapon(uint8_t _weapon);
	void Print() const;
	void SmartPrint() const;
private:
	uint8_t m_contents;
};

