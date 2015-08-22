/* *
*	Ariel Levin		ariel.lvn89@gmail.com
*	Oren Yulzary	orren5@gmail.com
*
* * */

#pragma warning( disable : 4996 )

#include <iostream>
#include <ctime>
#include "coach.h"
#include "company.h"
#include "employee.h"
#include "game.h"
#include "judge.h"
#include "league.h"
#include "person.h"
#include "player.h"
#include "privateInvestor.h"
#include "sponsor.h"
#include "team.h"

using namespace std;


int main()
{
	/* tm date time structure
	*	{ seconds, minutes, hours, days, months, years }
	*
	* * */

	Coach coach1(Employee(Person(1, "Gershon", tm{ 0, 0, 0, 6, 7, 1970 }, "Israel"), 5000, 2000));

	Coach coach2(Employee(Person(2, "Zilberg", tm{ 0, 0, 0, 15, 10, 1985 }, "Italy"), 4000, 1500));

	Team team1(coach1);
	Team team2(coach2);

	team1.addPlayer(Player(Employee(Person(3, "Micky", tm{ 0, 0, 0, 6, 7, 1970 }, "Israel"), 5000, 2000), (Player::POSITION)0, 4));
	team1.addPlayer(Player(Employee(Person(4, "Foo", tm{ 0, 0, 0, 6, 7, 1950 }, "Israel"), 7777, 2000), (Player::POSITION)1, 2));
	team1.addPlayer(Player(Employee(Person(5, "Goo", tm{ 0, 0, 0, 5, 12, 1950 }, "Israel"), 3614, 500), (Player::POSITION)2, 9));

	team1.addSponsor(Company(Sponsor(20000, tm{ 0, 0, 0, 1, 1, 2005 }), 534673121, "Elit", 10000));

	team2.addPlayer(Player(Employee(Person(6, "Elvis", tm{ 0, 0, 0, 11, 7, 1970 }, "France"), 5000, 2000), (Player::POSITION)5, 4));
	team2.addPlayer(Player(Employee(Person(7, "Gogo", tm{ 0, 0, 0, 10, 2, 2005 }, "Brasil"), 7777, 2000), (Player::POSITION)12, 3));
	team2.addPlayer(Player(Employee(Person(8, "Momo", tm{ 0, 0, 0, 5, 12, 1987 }, "India"), 3614, 500), (Player::POSITION)11, 10));

	team2.addSponsor(PrivateInvestor(Person(9, "Bil Gates", tm{ 0, 0, 0, 15, 3, 1975 }, "USA"), Sponsor(100000, tm{ 0, 0, 0, 7, 10, 2003 })));

	Judge judge1(Employee(Person(10, "Koko", tm{ 0, 0, 0, 20, 9, 1958 }, "Israel"), 9000, 0));
	Judge judge2(Employee(Person(11, "Asi", tm{ 0, 0, 0, 13, 11, 2003 }, "Israel"), 6500, 500));

	Game game1(team1, team2, judge1, tm{ 0, 0, 21, 13, 8, 2015 });
	Game game2(team1, team2, judge2, tm{ 0, 0, 21, 23, 8, 2015 });

	game1.getJudge().whistle();		// for start game
	game1.getJudge().whistle();		// for end game

	game2.getJudge().whistle();		// for start game
	game2.getJudge().redCard();
	game2.getJudge().whistle();		// for end game

	League league1("Champions League", tm{ 0, 0, 0, 1, 9, 2015 }, tm{ 0, 0, 0, 1, 10, 2015 });

	league1.addTeam(team1);
	league1.addTeam(team2);

	league1.addGame(game1);
	league1.addGame(game2);

	cout << "League 1:" << endl << league1 << endl;

	return 1;
}