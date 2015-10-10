#include "Player.h"
#include "Coach.h"
#include "Referee.h"
#include "Stadium.h"
#include "Team.h"
#include "League.h"
#include "Association.h"
#include "LinkedList.h"


int main()
{
	//************************************ Create team 1 *********************************
	//Create players for team 1
	Person person1("Eran Zahavi", 21);
	StaffMember staff1(person1, 20000, 3);
	Player player1(staff1, Player::STRICKER, 8);

	Person person2("Yoav Ziv", 26);
	StaffMember staff2(person2, 10000, 1);
	Player player2(staff2, Player::GOALKEEPER, 12);

	//Create coaches for team 1
	Person person3("Slavisa Jokanovic", 58);
	StaffMember staff3(person3, 70000, 30);
	Coach caoch1(staff3, Coach::HEAD);

	Person person4("Domingo Marin", 47);
	StaffMember staff4(person4, 33000, 15);
	Coach caoch2(staff4, Coach::ASSISTANT);

	//Create stadium for team 1
	Stadium stadium1("Blumfild", 40000, "Tel Aviv");

	//Crete team 1
	Team team1(stadium1, 13, "Maccabi");

	//Add the players and the coaches to the team
	team1 += player1;
	team1 += player2;
	team1 += caoch1;
	team1 += caoch2;

	//************************************ Create team 2 *********************************
	//Create players for team 2
	Person person11("Altman Omri", 21);
	StaffMember staff11(person11, 20000, 3);
	Player player11(staff11, Player::STRICKER, 8);

	Person person22("Danin Eyal", 26);
	StaffMember staff22(person22, 10000, 1);
	Player player22(staff22, Player::GOALKEEPER, 12);

	//Create coaches for team 2
	Person person33("Badir Walid", 58);
	StaffMember staff33(person33, 70000, 30);
	Coach caoch11(staff33, Coach::HEAD);

	Person person44("burstein gabriel", 47);
	StaffMember staff44(person44, 33000, 15);
	Coach caoch22(staff44, Coach::ASSISTANT);

	//Create stadium for team 2
	Stadium stadium2("Hapoel Stadium", 30000, "Tel Aviv");

	//Crete team 2
	Team team2(stadium2, 13, "Hapoel Tel Aviv");

	//Add the players and the coaches to the team
	team2 += player11;
	team2 += player22;
	team2 += caoch11;
	team2 += caoch22;

	//*********************************************************************************
	//Create referees for the entire association
	Person refereePerson1("Ben Zion Salman", 37);
	Referee referee1(refereePerson1, Referee::CENTER);

	Person refereePerson2("Naftali Eitan", 46);
	Referee referee2(refereePerson2, Referee::SIDELINE);

	Person refereePerson3("Ozi Itzhaki", 32);
	Referee referee3(refereePerson3, Referee::SIDELINE);

	Person refereePerson4("Ilan Barom", 24);
	Referee referee4(refereePerson4, Referee::ASISSTANT);

	//Create the league
	League league1("Ligat ha al", 2, 1);//two teams one game

	//Add both teams to the league
	league1 += team1;
	league1 += team2;

	//Create the football association
	Association association1(1, 4);//one league four referees

	//Add the referees to the association
	association1.addReferee(referee1);
	association1.addReferee(referee2);
	association1.addReferee(referee3);
	association1.addReferee(referee4);


	//Create a game between the two teams
	Referee** rf = new Referee*[4];
	rf[0] = &referee1;
	rf[1] = &referee2;
	rf[2] = &referee3;
	rf[3] = &referee4;
	Game theGame(stadium1, team1, team2, rf);

	//Add the game to the league
	league1 += theGame;

	//Add the league to the association
	association1.addLeague(league1);

	//Start the association - start the league - start the game
	association1.start();

	//other unused operators
	team1 -= player2;//Remove player from team
	league1 -= team1;//remove team from league
}