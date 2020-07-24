#include "Game.h"
#define LINE cout << "---------------------------------------------\n\n"

Game::Game(string redName, string blueName)
{
	red.SetName(redName);
	blue.SetName(blueName);

	red.GenerateTeam();
	blue.GenerateTeam();

	red.ShowTeam();
	blue.ShowTeam();
}

void Game::Step(vector<Unit>& attackingTeam, vector<Unit>& defendingTeam)
{
	for (int i = 0; i < attackingTeam.size(); i++)
	{
		if (attackingTeam[i].GetHealth() == 0)
			continue;

		Type redType = attackingTeam[i].GetType();
		int enemyNum;

		for (size_t j = 0; j < defendingTeam.size(); j++)
		{
			if (defendingTeam[j].GetType() == redType)
			{
				enemyNum = j;
				break;
			}
			else if (j == defendingTeam.size() - 1 && defendingTeam[j].GetType() != redType)
			{
				do
				{
					enemyNum = rand() % defendingTeam.size();
				} while (defendingTeam[enemyNum].GetHealth() <= 0);
				break;
			}
		}

		int status = defendingTeam[enemyNum].TakeDamage(attackingTeam[i].GetDamage());

		cout << "Attacking: ";
		attackingTeam[i].Print();
		cout << "Defender: ";
		defendingTeam[enemyNum].Print();

		if (status == 0)
			cout << "Damage: 0\n";
		else if (status == 1)
			cout << "Damage: " << attackingTeam[i].GetDamage() << endl;
		else if (status == -1)
			cout << "Defender dead.\n";
	}
}

void Game::Play()
{
	int round = 0;
	do
	{
		LINE;
		cout << "Round: " << ++round << "\n\n";

		cout << "\tTeam red is attacking\n";
		Step(red.team, blue.team);
		cout << endl;

		cout << "\tTeam blue is attacking\n";
		Step(blue.team, red.team);
		LINE;

	} while (!red.IsLose() && !blue.IsLose());

	if (red.IsLose())
		cout << "Blue team win!!!\n";
	else if (blue.IsLose())
		cout << "Red team win!!!\n";
}