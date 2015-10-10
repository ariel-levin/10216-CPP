#include <stdlib.h>
#include <time.h>

#include "Game.h"
#include "Player.h"


Game::Game(const Stadium& stadium, Team& team1, const Team& team2, const LinkedList<Referee>& referees) :
	stadium(stadium), team1(team1), team2(team2)
{
	this->referees = referees;
}

//Show the result of the game (randomly show a score and print the names of the players who scored..)
void Game::start() const throw (string)
{
	if (team1.getPlayerCounter() <= 0 || team2.getPlayerCounter() <= 0)
	{
		throw "can't start game because one or both of the teams doesn't have any players..";
	}
	else
	{ 
		srand((unsigned int)time(NULL));
		int scoreTeam1 = rand() % 6;
		int scoreTeam2 = rand() % 6;
		cout << ">>>> Game score >> Team1: " << scoreTeam1 << ", Team2: " << scoreTeam2 << endl << endl;
		cout << ">> Players scored on Team1:" << endl << endl;
		for (int i = 0; i < scoreTeam1; i++)
		{
			int playerIndex = rand() % team1.getSize();
			while (typeid(team1[playerIndex]) != typeid(Player))
			{
				playerIndex = rand() % team1.getSize();
			}
			cout << team1[playerIndex] << endl;
		}
		cout << ">> Players scored on Team2:" << endl << endl;
		for (int i = 0; i < scoreTeam2; i++)
		{
			int playerIndex = rand() % team2.getSize();
			while (typeid(team2[playerIndex]) != typeid(Player))
			{
				playerIndex = rand() % team2.getSize();
			}
			cout << team2[playerIndex] << endl;
		}
	}
}
