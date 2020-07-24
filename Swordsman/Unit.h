#pragma once

#include <iostream>

using namespace std;

enum Type
{
	SWORDSMAN,
	ARCHER,
	MAGE
};

class Unit
{
protected:

	size_t health;
	size_t damage;
	size_t dodge;
	Type type;

public:

	Unit(size_t health, size_t damage, size_t dodge, Type type);
	void SetHealth(size_t health);
	void SetDamage(size_t damage);
	void SetDodge(size_t dodge);
	void SetType(Type type);
	size_t GetHealth();
	size_t GetDamage();
	size_t GetDodge();
	Type GetType();
	void Print();
	int TakeDamage(size_t damage);
};