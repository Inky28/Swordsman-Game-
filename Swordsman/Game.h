#pragma once
#include <iostream>
#include "Team.h"

class Game
{
private:
	Team red;
	Team blue;
public:
	Game(string redName = "Red", string blueName = "Blue");
	void Step(vector<Unit>& attackingTeam, vector<Unit>& defendingTeam);
	void Play();
};