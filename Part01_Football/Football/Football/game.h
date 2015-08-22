#ifndef __GAME_H
#define __GAME_H

#include <iostream>
#include <ctime>
#include "team.h"
#include "judge.h"

using namespace std;


class Game
{
public:
	Game(const Team& team1, const Team& team2, const Judge& judge, const tm& startTime);
	Game(const Game& other);
	~Game();

	const Game& operator=(const Game& other);
	bool operator<(const Game& game);
	bool operator>(const Game& game);

	void setTeam1(const Team& team1);
	void setTeam2(const Team& team2);
	void setJudge(const Judge& judge);
	void setStartTime(const tm& startTime);
	void setEndTime(const tm& endDate);
	void setInGame(bool gameOn);

	const Team& getTeam1() const { return team1; };
	const Team& getTeam2() const { return team2; };
	const Judge& getJudge() const { return judge; };
	const tm& getStartTime() const { return startTime; };
	const tm* getEndTime() const { return endTime; };
	const bool isGameOn() const { return gameOn; };

	friend ostream& operator<<(ostream& os, const Game& g);

	void start() const;
	void end() const;

private:
	Team team1, team2;
	Judge judge;
	tm startTime;
	tm* endTime;
	bool gameOn;

};

#endif	// __GAME_H