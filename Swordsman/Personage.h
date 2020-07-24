#pragma once
#include "Unit.h"

class Swordsman : public Unit
{
public:
	Swordsman() : Unit(15, 5, 60, Type::SWORDSMAN) {}
};

class Archer : public Unit
{
public:
	Archer() : Unit(12, 4, 40, Type::ARCHER) {}
};

class Mage : public Unit
{
public:
	Mage() : Unit(8, 10, 30, Type::MAGE) {}
};