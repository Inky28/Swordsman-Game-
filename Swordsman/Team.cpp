#include "Team.h"
#include "Personage.h"
#define LINE cout << "\n========================================\n\n"

void Team::SetName(string name)
{
	if (!name.empty())
		this->name = name;
}

string Team::GetName()
{
	return name;
}

vector<Unit> Team::GetTeam()
{
	return team;
}

void Team::GenerateTeam(size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		Type type = Type(rand() % 3);
		switch (type)
		{
		case SWORDSMAN:
		{
			Swordsman unit;
			team.push_back(unit);
			break;
		}
		case ARCHER:
		{
			Archer unit;
			team.push_back(unit);
			break;
		}
		case MAGE:
		{
			Mage unit;
			team.push_back(unit);
			break;
		}
		}
	}
}

void Team::ShowTeam()
{
	LINE;
	cout << "\t\t" << GetName() << endl;
	for (Unit unit : team)
		unit.Print();
	LINE;
}

bool Team::IsLose()
{
	for (Unit unit : team)
		if (unit.GetHealth() > 0)
			return false;
	return true;
}