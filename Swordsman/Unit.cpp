#include "Unit.h"

Unit::Unit(size_t health, size_t damage, size_t dodge, Type type)
{
	SetHealth(health);
	SetDamage(damage);
	SetDodge(dodge);
	SetType(type);
}

void Unit::SetHealth(size_t health)
{
	if (health <= 100)
		this->health = health;
}

void Unit::SetDamage(size_t damage)
{
	if (damage <= 100)
		this->damage = damage;
}

void Unit::SetDodge(size_t dodge)
{
	if (dodge <= 100)
		this->dodge = dodge;
}

void Unit::SetType(Type type)
{
	if ((int)type >= 0 && (int)type < 3)
		this->type = type;
}

size_t Unit::GetHealth()
{
	return health;
}

size_t Unit::GetDamage()
{
	return damage;
}

size_t Unit::GetDodge()
{
	return dodge;
}

Type Unit::GetType()
{
	return type;
}

void Unit::Print()
{
	switch (GetType())
	{
	case SWORDSMAN:
		cout << "Class: SWORDSMAN, ";
		break;

	case ARCHER:
		cout << "Class: ARCHER, ";
		break;

	case MAGE:
		cout << "Class: MAGE, ";
		break;
	}

	cout << GetHealth() << " HP, ";
	cout << GetDamage() << " DMG, ";
	cout << GetDodge() << " %\n";
}

int Unit::TakeDamage(size_t damage)
{
	if ((rand() % 100 + 1) > dodge)
	{

		if (health < damage)
		{
			health = 0;
			return -1;
		}
		else
		{
			health -= damage;
			return 1;
		}
	}
	return 0;
}