#ifndef GAME_HPP
#define GAME_HPP

#include "Item.hpp"
#include "Room.hpp"
#include "LinkedList.hpp"

class Game
{
public:
	Game();
	~Game();
	void play();
private:
	enum EndCode {QUIT, OUTOFTIME, BABYCRIED, WON};
	/*** functions ***/
	void initialize();
	void startGame();
	void displayIntro();
	void displayEnding(EndCode e);
	void showMenuHelp();
	void showUseMenu();
	bool use(Item *i);
	void showMap();
	void showGoals();
	Room* findRoom(Room *r, int id);
	void resetSearch(Room *r);
	void getTimeLimit();
	bool isTimeUp();
	int getTimeLeft();
	int getCryTimeLeft();
	bool updateWin(int item); /* returns true if you have won the game */
	/*** variables ***/
	bool hasLight;
	LinkedList inv; /* inventory, the objects you can use */
	int numItems;
	int maxItems;
	Room *curr; /* current location */
	/* time limits - baby */
	bool babyCrying;
	int cryTimeLimit;
	time_t cryStartTime;
	bool cryWarning1;
	bool cryWarning2;
	/* time limits - game */
	int timeLimit; /* in seconds */
	time_t startTime;
	bool gameWarning1;
	bool gameWarning2;
	/* checks for winning the game */
	bool paper;
	bool marker;
	bool oj;
	bool toast;
	bool eggs;
	bool flowers;
	bool turkDelight;
	bool keepPlaying; /* user keeps playing after getting required items */
};

#endif