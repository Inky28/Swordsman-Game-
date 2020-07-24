#pragma once
#include <iostream>
#include <vector>
#include "Unit.h"

class Team
{
private:
	string name;
public:
	vector<Unit> team;
	void SetName(string name);
	string GetName();
	vector<Unit> GetTeam();
	void GenerateTeam(size_t size = 3);
	void ShowTeam();
	bool IsLose();
};
