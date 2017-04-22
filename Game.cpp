#include "Game.hpp"
#include "Backyard1.hpp"
#include "Backyard2.hpp"
#include "Coop.hpp"
#include "Crib.hpp"
#include "Dining.hpp"
#include "Hallway1.hpp"
#include "Hallway2.hpp"
#include "Hedges.hpp"
#include "Kitchen.hpp"
#include "Living1.hpp"
#include "Living2.hpp"
#include "Nursery.hpp"
#include "Roses.hpp"
#include "Study.hpp"
#include "Tommys.hpp"
#include "UtilityLib.hpp"
#include <iostream>
#include <ctime>


/*********************************************************************
** Function: Game()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Member variables and linked rooms initialized
*********************************************************************/
Game::Game()
{
	initialize(); /* initializes curr */
	hasLight = false;
	numItems = 0;
	maxItems = 3;
	babyCrying = false;
	cryTimeLimit = 0;
	cryStartTime = -1;
	cryWarning1 = false;
	cryWarning2 = false;
	timeLimit = 0;
	startTime = -1;
	gameWarning1 = false;
	gameWarning2 = false;
	paper = false;
	marker = false;
	oj = false;
	toast = false;
	eggs = false;
	flowers = false;
	turkDelight = false;
	keepPlaying = false;
}


/*********************************************************************
** Function: Game()
** Description: Default destructor begins deletion from current Room
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory deallocated
*********************************************************************/
Game::~Game()
{
	delete curr;
}


/*********************************************************************
** Function: initialize()
** Description: Dynamically allocates all rooms, links them
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Rooms initialized and linked
*********************************************************************/
void Game::initialize()
{	
	/* create rooms */
	Room *room3 = new Hallway1();
	Room *room4 = new Nursery();
	Room *room5 = new Study();
	Room *room6 = new Hallway2();
	Room *room7 = new Tommys();
	Room *room8 = new Crib();
	Room *room9 = new Kitchen();
	Room *room10 = new Living1();
	Room *room11 = new Dining();
	Room *room12 = new Living2();
	Room *room13 = new Backyard1();
	Room *room14 = new Hedges();
	Room *room15 = new Roses();
	Room *room16 = new Backyard2();
	Room *room17 = new Coop();

	/* link rooms */
	room3->setSouth(room6);
	room3->setEast(room4);

	room4->setWest(room3);

	room5->setEast(room6);

	room6->setNorth(room3);
	room6->setSouth(room10);
	room6->setEast(room7);
	room6->setWest(room5);

	room7->setWest(room6);
	room7->setEast(room8);

	room8->setWest(room7);

	room9->setSouth(room11);
	room9->setEast(room10);

	room10->setNorth(room6);
	room10->setSouth(room12);
	room10->setWest(room9);

	room11->setEast(room12);
	room11->setNorth(room9);

	room12->setNorth(room10);
	room12->setEast(room13);
	room12->setWest(room11);

	room13->setSouth(room16);
	room13->setEast(room14);
	room13->setWest(room12);

	room14->setEast(room15);
	room14->setWest(room13);

	room15->setWest(room14);

	room16->setNorth(room13);
	room16->setSouth(room17);

	room17->setNorth(room16);

	/* initialize curr, starting position */
	curr = room8;
}


/*********************************************************************
** Function: startGame()
** Description: Display elements to start the game: game introduction,
** selection difficulty level, "tutorial", story transition text
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Storyline outputted before gameplay, time limit set
*********************************************************************/
void Game::startGame()
{
	clearScreen();
	
	/* print intro text and heading */
	displayIntro();
	std::cout << std::endl;

	/* prompt for difficulty level / time limit */
	getTimeLimit();

	/* instructions are printed if you selected the "easy" level */
	if (timeLimit >= 2700)
	{
		/* explain the menu*/
		showMenuHelp();

		/* show goals */
		std::cout << std::endl << "GAME OBJECTIVES" << std::endl << std::endl;
		std::cout << "Select Option 7 in Main Menu to view your progress at any time." << std::endl;
		showGoals();
		std::cout << std::endl;

		std::cout << "Press ENTER to continue...";
		std::cin.ignore(1000, '\n');

		/* show map */
		std::cout << std::endl << "GETTING AROUND" << std::endl << std::endl;
		std::cout << "Select Option 6 in Main Menu to view this map at any time." << std::endl;
		std::cout << "You begin the game in the Crib, which is inside Tommy's Room." << std::endl << std::endl;
		showMap();
	}
	else
		std::cout << std::endl;

	std::cout << "You've been lying quietly in your crib, fighting the good fight to stay awake\n"
		"while waiting for Mommy and Daddy to go to bed. It seems to be time!" << std::endl << std::endl;

	std::cout << "Press ENTER to begin the game!";
	std::cin.ignore(1000, '\n');
}


/*********************************************************************
** Function: displayIntro()
** Description: Displays story / ASCII art intro. Helper function to
** startGame()
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Story/intro outputted
*********************************************************************/
void Game::displayIntro()
{
	std::cout << "It was a dark and stormy night... well, no. This is not that kind of game."
		<< std::endl << std::endl;

	std::cout << "Welcome to the turbulent life of Tommy Tucker, whose peaceful idyll of a home\n"
		"has been mercilessly shattered with the arrival of your baby sister (AKA The\n"
		"Creature) from the hospital several months ago. This very loud, very annoying\n"
		"wrinkled pest has taken over the house with her frilly pink things and seems\n"
		"to live in Mommy's arms. Last night, when she started screaming during story\n"
		"time, was the last straw!" << std::endl << std::endl;

	std::cout << "But you have come up with the perfect plan to win the Favorite Child blue\n"
		"ribbon: you're going to make tomorrow the PERFECT Mother's Day. Whether it's\n"
		"outsmarting child safety locks, stealing construction paper from the study, or\n"
		"clipping your neighbor's roses (guarded by her dog), you'll stop at nothing.\n"
		"But you don't have long, and you'll be in big trouble if you're caught (by the\n"
		"dog or your parents). The Creature has sharp ears (and a big mouth), too!" << std::endl << std::endl;

	std::cout << "Press ENTER to continue..." << std::endl;
	std::cin.ignore(1000, '\n');

	std::cout << std::endl << "     Welcome to" << std::endl;
	std::cout << "          ___________                           /\\     " << std::endl;
	std::cout << "          \\__    ___/___   _____   _____ ___.__.)/_____" << std::endl;
	std::cout << "            |    | /  _ \\ /     \\ /     <   |  |/  ___/" << std::endl;
	std::cout << "            |    |(  <_> )  Y Y  \\  Y Y  \\___  |\\___ \\ " << std::endl;
	std::cout << "            |____| \\____/|__|_|  /__|_|  / ____/____  >" << std::endl;
	std::cout << "                               \\/      \\/\\/         \\/ " << std::endl;
	std::cout << "          ___________                  ___.   .__          " << std::endl;
	std::cout << "          \\__    ___/______  ____  __ _\\_ |__ |  |   ____  " << std::endl;
	std::cout << "            |    |  \\_  __ \\/  _ \\|  |  \\ __ \\|  | _/ __ \\ " << std::endl;
	std::cout << "            |    |   |  | \\(  <_> )  |  / \\_\\ \\  |_\\  ___/ " << std::endl;
	std::cout << "            |____|   |__|   \\____/|____/|___  /____/\\___  >" << std::endl;
	std::cout << "                                            \\/          \\/ " << std::endl;
	std::cout << "               \"The Sweetest Mother's Day Revenge ?!\"" << std::endl << std::endl;
	/* ASCII art courtesy of generator at http://patorjk.com/software/taag/ */

	std::cout << "Press ENTER to continue...";
	std::cin.ignore(1000, '\n');
}


/*********************************************************************
** Function: displayEnding(EndCode e)
** Description: Displays appropriate ending depending on if you win, lose,
** quit
** Parameters: EndCode e
** Pre-Conditions: None
** Post-Conditions: Storyline outputted
*********************************************************************/
void Game::displayEnding(EndCode e)
{
	std::cout << std::endl;
	if (e == QUIT)
	{
		std::cout << "Who would have guessed that Mother's Day would be such a challenge? You end\n"
			"the night a bit cold, rather hungry, and tired, curling up on the couch since\n"
			"you can't quite climb back into your crib." << std::endl << std::endl;

		std::cout << "You wake up to Mommy's puzzled voice above you. 'Tommy?' she says. 'What are\n"
			"you doing out here?' Of course, she is carrying the Creature in her arms. But\n"
			"in the soft light of day, even The Creature doesn't look quite so menacing.\n"
			"With the fat cheeks, chubby arms, and big blue eyes, she might even be... cute?\n"
			"You sigh in resignation." << std::endl << std::endl;
	}
	else if (e == OUTOFTIME)
	{
		std::cout << "Your eyelids dip closed... Just for a little while, you tell yourself, and a\n"
			"deep and comforting darkness overtakes you." << std::endl << std::endl;

		std::cout << "You wake up to Mommy's puzzled voice above you. 'Tommy?' she says. 'What are\n"
			"you doing out here?' Of course, she is carrying the Creature in her arms. But\n"
			"in the soft light of day, even The Creature doesn't look quite so menacing.\n"
			"With the fat cheeks, chubby arms, and big blue eyes, she might even be... cute?\n"
			"You sigh in resignation." << std::endl << std::endl;
	}
	else if (e == BABYCRIED)
	{
		std::cout <<
			"You hear shuffling footsteps moving across the house. 'Tommy?' says your dad's\n"
			"voice. 'What are you doing up?' 'Well,' you hedge. You are tempted to play\n"
			"possum and collapse in a sleeping heap on the spot. Somehow, you think he would\n"
			"see right through you." << std::endl << std::endl;
		std::cout <<
			"So you confess. And when the full story comes out, dad gives you a BIG hug.\n"
			"'Son,' he says, 'I'm proud of you.' Okay, so maybe you underplayed the part\n"
			"about revenge and vying for the Favorite Child Award. You start to feel a bit\n"
			"guilty. 'Let's go to bed for now, and I'll help you make a great Mother's Day\n"
			"breakfast in the morning, all right?'" << std::endl << std::endl;
		std::cout <<
			"Well, that really sounds like a good deal right now. He wraps his arms around\n"
			"you, picks you up, and carries you to bed. In the morning, you and Daddy\n"
			"bring Mommy breakfast in bed -- of course, she's sitting there with the\n"
			"Creature in her arms. But in the soft light of day, even The Creature doesn't\n"
			"look quite so menacing. With the fat cheeks, chubby arms, and big blue eyes,\n"
			"she might even be... cute? You sigh in resignation." << std::endl << std::endl;
	}
	else /* if e == WON */
	{
		std::cout <<
			"YOU DID IT!!! In the morning, Mommy is just glowing, and you watch with great\n"
			"expectation as she takes a small bite of leftover toast and sips orange\n"
			"juice delicately from the sippy cup. 'Mmm,' she says loudly. You smile brightly\n"
			"and bring out the roses from behind your back." << std::endl << std::endl;

		std::cout <<
			"'Oh!' she says. 'Where did you... Those wouldn't be...' She clears her throat,\n"
			"clearly overcome by great emotion." << std::endl << std::endl;

		if (turkDelight)
			std::cout << "'There's even Turkish delight!' she gasps." << std::endl << std::endl;

		std::cout <<
			"Mommy gathers you close for a big hug. 'I love you SO much, darling,' she\n"
			"says, 'with or without any Mother's Day gifts. But this was very, very\n"
			"sweet.'" << std::endl << std::endl;

		std::cout <<
			"You sneak a gloating look at The Creature, who is lying on the bed, but\n"
			"she is annoyingly placid about all of this. In fact, she chooses this very\n"
			"moment to let out a sweet, burbling laugh. Probably gas, you think in\n"
			"disgust. But in the soft morning light, as she looks adoringly up at you\n"
			"with shining blue eyes, she might even be... cute? You sigh in resignation.\n"
			<< std::endl;
		std::cout << "Press ENTER to continue..." << std::endl;
		std::cin.ignore(1000, '\n');

		std::cout <<
			"Afterword: Mom's Journal Entry" << std::endl;
		std::cout <<
			"     The sweetest and strangest thing happened today. Tommy made me a\n"
			"very memorable Mother's Day breakfast and card. There were even the most\n"
			"gorgeous roses -- though I'm a bit afraid to see Mrs. Spencer's thunderous\n"
			"expression this morning." << std::endl;
		std::cout <<
			"     The damage: mud tracks in the living room, trash all over the kitchen,\n"
			"a gardening spade in the hen coop (\?\?\?), many other moved or missing items.\n"
			"Oh, and the toast was leftover from last night's dinner. All in all, the\n"
			"best Mother's Day EVER!!!" << std::endl << std::endl;
	}

	std::cout << "THE END" << std::endl;
	std::cout << "Press ENTER to continue..." << std::endl;
	std::cin.ignore(1000, '\n');
}


/*********************************************************************
** Function: showMenuHelp()
** Description: Explanation of the actions in the main menu
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Explanation of main menu outputted
*********************************************************************/
void Game::showMenuHelp()
{
		std::cout << std::endl << "Quickstart Tutorial: The Main Menu Explained" << std::endl << std::endl;
		std::cout << "1: Move -- Shows what is in each adjacent space." << std::endl;
		std::cout << "2: Get -- Shows the objects in the room that you can pick up." << std::endl;
		std::cout << "3: Use -- Shows the items in your inventory that you can use." << std::endl;
		std::cout << "4: Open -- Shows the objects (doors, drawers, etc.) you can open." << std::endl;
		std::cout << "5: Look -- Shows the room description and objects, which may be clues.\n"
			"Remember, actions you have taken may reveal new objects in the room." << std::endl;
		std::cout << "6: Map -- Displays a map." << std::endl;
		std::cout << "7: Goals -- Shows your goals and progress." << std::endl;
		std::cout << "8: Quit -- Ends the game without saving. Mom will be so disappointed!" << std::endl << std::endl;

		std::cout << "Press ENTER to continue...";
		std::cin.ignore(1000, '\n');
}


/*********************************************************************
** Function: play()
** Description: The primary loop that drives the game by asking the user
** what action s/he would like to take next
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Prompts user for action until time runs out, quit, or
** game is won
*********************************************************************/
void Game::play()
{
	/* introduction */
	startGame();

	/* set timer to start */
	time(&startTime);

	/* enter the starting room */
	curr->enter(hasLight);
	std::cout << std::endl;

	int select = 0;
	bool complete = false;
	Room *next;

	while (!complete)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "     1: Move             5: Look" << std::endl;
		std::cout << "     2: Get              6: Map" << std::endl;
		std::cout << "     3: Use              7: Goal" << std::endl;
		std::cout << "     4: Open             8: Quit" << std::endl;

		/* read user input */
		std::cin >> select;
		std::cin.ignore(1000, '\n');

		switch (select)
		{
		case 1: /* move */
			next = curr->showDirections();
			if (next == NULL)
				std::cout << "Ouch! You can't go in that direction!" << std::endl;
			else
			{
				/* save previous location in case enter returns false */
				Room *prev = curr;
				curr = next;
				/* if enter returns false */
				if (!next->enter(hasLight))
				{
					/* one chance to use an object before chased out */
					showUseMenu();
					if (!next->getStay())
					{
						std::cout << "You're forced to retreat!" << std::endl;
						prev->enter(hasLight);
						curr = prev;
					}
				}
				if (curr->getID() == 4 && babyCrying) /* nursery */
					std::cout << "   The piercing sound of a screaming baby seems to shake the room." << std::endl;
			}
			break;
		case 2: /* get */
			if (numItems >= maxItems)
				std::cout << "Your hands are full. Maybe use a container?" << std::endl;
			else
			{
				Item* toGet = curr->showGetMenu(hasLight);
				if (toGet != NULL)
				{
					/* check if game is won */
					complete = updateWin(toGet->getID());
					/* picking up roses triggers baby crying */
					if (!complete && toGet->getID() == 151)
					{
						babyCrying = true;
						time(&cryStartTime);
						std::cout << std::endl << "You hear a wailing cry rise up. Uh oh, all the barking earlier must have\n"
							"woken The Creature! You'd better calm her down before she wakes Mommy and\n"
							"Daddy up!" << std::endl;
					}
					/* add the item you picked up to your inventory */
					inv.add(toGet);
					numItems++;
				}
			}
			break;
		case 3: /* use */
			showUseMenu();
			break;
		case 4: /* open */
			curr->showOpenMenu(hasLight);
			break;
		case 5: /* look */
			curr->print(hasLight);
			if (curr->getID() == 4 && babyCrying) /* nursery */
				std::cout << "   The piercing sound of a screaming baby seems to shake the room." << std::endl;
			break;
		case 6: /* map */
			showMap();
			break;
		case 7: /* goals */
			showGoals();
			break;
		case 8: /* quit - let the loop end */
			std::cout << "Are you sure? (Y/N)" << std::endl;
			complete = getYesNo();
			if (complete)
				displayEnding(QUIT);
			break;
		default: /* invalid menu option */
			std::cout << std::endl << "Please select a valid option." << std::endl;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}
		std::cout << std::endl;
		select = 0;

		/* check if time is up, don't reset if case 8 was selected */
		/* displayEnding called from isTimeUp() */
		if (!complete && isTimeUp())
			complete = true;
	}
}


/*********************************************************************
** Function: showUseMenu()
** Description: Displays menu of things to use from inventory
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Menu outputted, item to use selected (or back to
** main menu). Sometimes trying to use the item will fail.
*********************************************************************/
void Game::showUseMenu()
{
	/* dark */
	if (!hasLight && !curr->getLight())
		std::cout << "You manage to feel around for your things in the dark..." << std::endl;
	/* empty inventory */
	if (inv.isEmpty())
		std::cout << "You don't have anything to use right now." << std::endl;
	else
	{
		std::cout << std::endl << "What would you like to use?" << std::endl;
		/* get selection */
		Item* toUse = inv.displayAsMenu();
		if (toUse != NULL)
		{
			/* item can be used anywhere (-1), or can be used in current room */
			if (toUse->getActive() == -1 || toUse->getActive() == curr->getID())
			{
				Room *r = NULL;
				bool success = true;

				/* find the target room, call Game use() if -1 */
				if (toUse->getTarget() == -1)
					success = use(toUse);
				else if (toUse->getTarget() == curr->getID())
					r = curr;
				else /* find the target room */
				{
					r = findRoom(curr, toUse->getTarget());
					resetSearch(r);
				}
				/* call Room use() */
				if (r != NULL)
					success = r->use(toUse);
				if (success)
				{
					/* remove item from inventory if successfully used */
					inv.remove(toUse);
					delete toUse;
					numItems--;
				}
			}
			else /* wrong room or not an object to use */
			{
				if (toUse->getActive() == 0) /* it's a goal item */
					std::cout << "You'd better hold on to that." << std::endl;
				else
					std::cout << "There might be somewhere better to use that." << std::endl;
			}
		}
	}
}


/*********************************************************************
** Function: use(Item *i)
** Description: Helper function for items that need to be used at the
** Game level, because they affect the entire game and not a specific
** Room
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: If the Item is a match, take the appropriate action
** in the game
*********************************************************************/
bool Game::use(Item *i)
{
	if (i->getID() == 70) /* backpack */
	{
		i->use();
		maxItems = 25;
		return true;
	}
	if (i->getID() == 40) /* nightlight */
	{
		i->use();
		hasLight = true;
		return true;
	}
	if (i->getID() == 100) /* pacifier */
	{
		if (babyCrying)
		{
			i->use();
			babyCrying = false;
			return true;
		}
		else
		{
			std::cout << "What for? She's sleeping peacefully." << std::endl;
			return false;
		}
	}
	return false;
}


/*********************************************************************
** Function: showMap()
** Description: Outputs a map of the world
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Map outputted
*********************************************************************/
void Game::showMap()
{
	std::cout << "                     A MAP OF THE WORLD" << std::endl << std::endl;
	std::cout << "                           Secret" << std::endl;
	std::cout << "                              |" << std::endl;
	std::cout << "                           Secret" << std::endl;
	std::cout << "                              X" << std::endl;
	std::cout << "    Parents X  Hallway1 -  Nursery" << std::endl;
	std::cout << "                  |" << std::endl;
	std::cout << "     Study  -  Hallway2 X Tommy's Room" << std::endl;
	std::cout << "                  |" << std::endl;
	std::cout << "    Kitchen -  Living1" << std::endl;
	std::cout << "       |          |" << std::endl;
	std::cout << "    Dining  -  Living2  X Backyard1  -  Hedges - Roses" << std::endl;
	std::cout << "                              |" << std::endl;
	std::cout << "                          Backyard2" << std::endl;
	std::cout << "                              X" << std::endl;
	std::cout << "                         Chicken Coop" << std::endl << std::endl;
	std::cout << "Notes: X indicates a closed door." << std::endl;
	std::cout << "       Actual space may vary slightly depending on actions." << std::endl;
	std::cout << std::endl;
	std::cout << "Press ENTER to continue..." << std::endl;
	std::cin.get();
}


/*********************************************************************
** Function: showGoals()
** Description: Shows goals and indicates progress
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Goals and progress outputted
*********************************************************************/
void Game::showGoals()
{
	std::cout << std::endl;
	std::cout << "Gather the ingredients for a perfect Mother's Day!" << std::endl;
	std::cout << "   Materials to make a card:" << std::endl;
	std::cout << "      paper";
	if (paper)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "      markers";
	if (marker)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "   Ingredients for breakfast:" << std::endl;
	std::cout << "      toast";
	if (toast)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "      eggs";
	if (eggs)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "      a cup of orange juice";
	if (oj)
		std::cout << "*";
	std::cout << std::endl;
	
	std::cout << "   Flowers";
	if (flowers)
		std::cout << "*";
	std::cout << std::endl;
	
	std::cout << "   BONUS: Turkish delight (Mom's favorite!)";
	if (turkDelight)
		std::cout << "*";
	std::cout << std::endl << std::endl;
	
	/* time updates */
	std::cout << "Game Time Remaining: " << getTimeLeft() << " secs" << std::endl;
	if (babyCrying)
		std::cout << "Baby Crying! Time Remaining: " << getCryTimeLeft() << " secs" << std::endl;
	
	std::cout << std::endl;
	std::cout << "* Acquired" << std::endl;
}


/*********************************************************************
** Function: findRoom(Room *r, int id)
** Description: Searches for a Room by ID and returns a pointer if found
** else NULL
** Parameters: Room *r, int id
** Pre-Conditions: None
** Post-Conditions: Returns Room* if found, else NULL
*********************************************************************/
Room* Game::findRoom(Room *r, int id)
{
	/* stop if this room has already been searched */
	if (r->getSearched() == true)
		return NULL;
	else
	{
		/* mark as searched */
		r->setSearched(true);

		/* check id */
		if (r->getID() == id)
			return r;
		else
		{
			Room *result;
			/* search north */
			if (r->getNorth() != NULL && r->getNorth()->getSearched() == false)
			{
				result = findRoom(r->getNorth(), id);
				if (result != NULL)
					return result;
			}

			/* search south */
			if (r->getSouth() != NULL && r->getSouth()->getSearched() == false)
			{
				result = findRoom(r->getSouth(), id);
				if (result != NULL)
					return result;
			}

			/* search east */
			if (r->getEast() != NULL && r->getEast()->getSearched() == false)
			{
				result = findRoom(r->getEast(), id);
				if (result != NULL)
					return result;
			}

			/* search west */
			if (r->getWest() != NULL && r->getWest()->getSearched() == false)
			{
				result = findRoom(r->getWest(), id);
				if (result != NULL)
					return result;
			}

			/* not found in any direction */
			return NULL;
		}
	}
}


/*********************************************************************
** Function: resetSearch(Room *r)
** Description: Called from any point in the map, this function marks
** all Rooms as not searched
** Parameters: Room *r
** Pre-Conditions: None
** Post-Conditions: All connected Rooms marked as not searched
*********************************************************************/
void Game::resetSearch(Room * r)
{
	if (r->getSearched())
	{
		r->setSearched(false);

		if (r->getNorth() != NULL && r->getNorth()->getSearched() == true)
			resetSearch(r->getNorth());

		if (r->getSouth() != NULL && r->getSouth()->getSearched() == true)
			resetSearch(r->getSouth());

		if (r->getEast() != NULL && r->getEast()->getSearched() == true)
			resetSearch(r->getEast());

		if (r->getWest() != NULL && r->getWest()->getSearched() == true)
			resetSearch(r->getWest());
	}
	
	return;
}


/*********************************************************************
** Function: getTimeLimit()
** Description: Prompts user to select difficulty level, sets time limits
** accordingly
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Time limits set
*********************************************************************/
void Game::getTimeLimit()
{
	int select = 0;

	while (timeLimit == 0)
	{
		std::cout << "Please select the difficulty level of your game:" << std::endl;
		std::cout << "     1: Easy (45 minutes) - includes tutorial" << std::endl;
		std::cout << "     2: Medium (20 minutes)" << std::endl;
		std::cout << "     3: Hard (10 minutes)" << std::endl;

		/* read user input */
		std::cin >> select;
		std::cin.ignore(1000, '\n');

		switch (select)
		{
			case 1:
				timeLimit = 2700; /* in seconds */
				cryTimeLimit = 360; /* 6 minutes */
				break;
			case 2:
				timeLimit = 1200;
				cryTimeLimit = 240; /* 4 minutes */
				break;
			case 3:
				timeLimit = 600;
				cryTimeLimit = 180; /* 3 minutes */
				break;
			default: /* invalid menu option */
				std::cout << "Please select a valid option." << std::endl << std::endl;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
				}
		}
	}
}


/*********************************************************************
** Function: isTimeUp()
** Description: Check if game time or crying time limits are up. Outputs
** warnings at intervals.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns true if game is over, or false if no time limits
** are yet surpassed. Outputs warnings at intervals.
*********************************************************************/
bool Game::isTimeUp()
{
	/* for the game */
	int timeLeft = getTimeLeft();
	/* warning 1 at < 3 mins left */
	if (!gameWarning1 && timeLeft > 60 && timeLeft <= 180)
	{
		std::cout << "Your eyelids are getting awfully heavy... You had better wrap this up soon."
			<< std::endl << std::endl;
		gameWarning1 = true;
	}
	/* warning 2 at < 1 min left */
	else if (!gameWarning2 && timeLeft > 0 && timeLeft <= 60)
	{
		std::cout << "Blink... Blink... Wait, where are you again? You just want to curl up somewhere\n"
			"soft and warm." << std::endl << std::endl;
		gameWarning2 = true;
	}
	/* end game at <= 0 min left */
	if (timeLeft <= 0)
	{
		if (keepPlaying) /* player has won but going for bonus item */
		{
			std::cout << "You've run out of time! It would have been nice to get Mommy something\n"
				"extra, but this is pretty good already. Unable to continue, you curl up and\n"
				"surrender to sleep." << std::endl << std::endl;
			displayEnding(WON);
		}
		else /* player lost */
			displayEnding(OUTOFTIME);
		return true;
	}

	/* for crying baby */
	if (babyCrying)
	{
		int babyTime = getCryTimeLeft();
		
		/* warning 1 at < 2 mins left */
		if (!cryWarning1 && babyTime >= 60 && babyTime < 120)
		{
			std::cout << "A particularly loud wail makes you shudder. You've got to get the Creature\n"
				"quiet before someone wakes up!" << std::endl << std::endl;
			cryWarning1 = true;
		}
		/* warning 2 at < 1 min left */
		else if (!cryWarning2 && babyTime >= 1 && babyTime < 60)
		{
			std::cout << "The Creature's sobbing has broken off into a high-pitched scream now. Just what\n"
				"are you waiting for?!" << std::endl << std::endl;
			cryWarning2 = true;
		}
		/* end game at <= 0 mins left */
		else if (babyTime <= 0)
		{
			if (keepPlaying) /* already gathered all required Items */
			{
				std::cout << "Uh oh, you hear footsteps! It would have been nice to get Mommy something\n"
					"extra, but this is pretty good already. You dash to your room and pretend to be\n"
					"asleep. Before you know it, the sounds of crying fade away... ZzzZzz..." << std::endl << std::endl;
				displayEnding(WON);
			}
			else
				displayEnding(BABYCRIED);
			return true;
		}
	}
	return false;
}


/*********************************************************************
** Function: getTimeLeft()
** Description: Returns seconds remaining in game overall
** Parameters: None
** Pre-Conditions: startTime initialized when game began
** Post-Conditions: Returns seconds remaining in game overall
*********************************************************************/
int Game::getTimeLeft()
{
	/* get current time */
	time_t currTime;
	time(&currTime);

	/* check time limit for game overall */
	int gameTime = static_cast<int>(difftime(currTime, startTime)); /* truncated */
	return timeLimit - gameTime;
}


/*********************************************************************
** Function: getCryTimeLeft()
** Description: Returns seconds remaining in game before baby crying
** wakes parents up
** Parameters: None
** Pre-Conditions: cryStartTime initialized when babyCrying was set to true
** Post-Conditions: Returns seconds remaining in game
*********************************************************************/
int Game::getCryTimeLeft()
{
	/* get current time */
	time_t currTime;
	time(&currTime);

	/* time remaining until parents wake */
	int cryTime = static_cast<int>(difftime(currTime, cryStartTime));
	return cryTimeLimit - cryTime;
}


/*********************************************************************
** Function: updateWin(int item)
** Description: Returns true to complete the game, else false. Option to
** continue playing (false) if you want to get the bonus item.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns true to complete the game, else false if
** not all winning items collected.
*********************************************************************/
bool Game::updateWin(int item)
{
	/* check required items */
	if (item == 50)
		marker = true;
	else if (item == 51)
		paper = true;
	else if (item == 110)
		toast = true;
	else if (item == 121)
		oj = true;	
	else if (item == 151)
		flowers = true;
	else if (item == 170)
		eggs = true;
	else if (item == 10) /* check bonus item */
		turkDelight = true;
	
	if (paper && marker && oj && toast && eggs && flowers && !keepPlaying)
	{
		if (!turkDelight)
		{
			/* have all required items but not Turkish delight */
			std::cout << "You have collected all the needed items, but you still have some time. Do you\n"
				"want to keep playing until you get the bonus item? (Y/N)" << std::endl;
			keepPlaying = getYesNo();
			if (!keepPlaying)
				displayEnding(WON);
			return !keepPlaying;
		}
		else
		{
			/* already had the Turkish delight when you gathered all required items */
			std::cout << "You collected all the items!" << std::endl << std::endl;
			displayEnding(WON);
			return true;
		}
	}
	/* acquired the Turkish delight */
	else if (keepPlaying && turkDelight)
	{
		std::cout << "You collected all the items!" << std::endl << std::endl;
		displayEnding(WON);
		return true;
	}
	
	return false;
}