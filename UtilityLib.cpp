#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


/*** DISPLAY FUNCTIONS ***/


/*********************************************************************
** Function: clearScreen()
** Description: Clears the console for Windows or Unix
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Console is clear
*********************************************************************/
void clearScreen()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
	/* Code written after consulting: 
	http://stackoverflow.com/questions/228617/how-do-i-clear-the-console-in-both-windows-and-linux-using-c */
}


/*********************************************************************
** Function: waitMillisec(int millisec)
** Description: Sleeps for Windows or Unix
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Next process waits x milliseconds
*********************************************************************/
void waitMillisecs(int millisec)
{
	#ifdef _WIN32
		Sleep(millisec);
		/* Explanation of function parameter units found
		http://stackoverflow.com/questions/2252372/how-do-you-make-a-program-sleep-in-c-on-win-32 */
	#else
		usleep(millisec * 1000);
	#endif
}


/*********************************************************************
** Function: formatDecimal(double d, int precision)
** Description: Returns double in string format, formatted to precision
** digits of precision after the decimal
** Parameters: double d, int precision
** Pre-Conditions: None
** Post-Conditions: Returns truncated string form of double
*********************************************************************/
std::string formatDecimal(double d, int precision)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(precision) << d;
	return oss.str();
}


/*** INPUT VALIDATION FUNCTIONS ***/


/*********************************************************************
** Function: getYesNo()
** Description: Reads user input and prompts for new input until
** reads Y or N (case insensitive)
** Parameters: None
** Pre-Conditions: What the user should input specified in calling function
** Post-Conditions: Returns true if yes, false if no
*********************************************************************/
bool getYesNo()
{
	char c;
	c = tolower(std::cin.get());

	while (std::cin.fail() || (c != 'y' && c != 'n'))
	{
		std::cout << "Invalid input. Please enter Y or N." << std::endl;
		std::cin.clear();
		if (c != '\n')
			std::cin.ignore(1000, '\n');
		c = tolower(std::cin.get());
	}

	std::cin.ignore(1000, '\n');
	if (c == 'y')
		return true;
	else /* if (c == 'n') */
		return false;
}


bool getSimpleTrigger(std::string prompt, std::string desc, std::string success)
{
	int select = -1;
	bool result = false;

	while (!result && select != 2)
	{
		std::cout << prompt << std::endl;
		std::cout << "     1: " << desc << std::endl;
		std::cout << "     2: Back to Main Menu" << std::endl;

		std::cin >> select;
		std::cin.ignore(1000, '\n');

		switch (select)
		{
		case 1:
			std::cout << success << std::endl;
			result = true;
			break;
		case 2:
			/* break out of loop */
			break;
		default:
			std::cout << std::endl << "Please select a valid option." << std::endl;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}
	}
	return result;
}


/*********************************************************************
** Function: getPosIntInput()
** Description: Reads user input and prompts for new input until
** a positive integer
** Parameters: None
** Pre-Conditions: What the user should input specified in calling function
** Post-Conditions: Returns positive int
*********************************************************************/
int getPosIntInput()
{
	int i;
	std::cin >> i;

	/* retrieve an int > 0 */
	while (std::cin.fail() || i <= 0)
	{
		std::cout << "Invalid input. Please enter a positive integer." << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> i;
	}

	std::cin.ignore(1000, '\n');
	return i;
	/* use of cin.fail() inspired by
	** http://stackoverflow.com/questions/18728754/checking-input-value-is-an-integer */
}


/*********************************************************************
** Function: getPosIntInput(int limit)
** Description: Reads user input and prompts for new input until it is
** an int between 1 and limit (inclusive)
** Parameters: int limit
** Pre-Conditions: limit is >= 1
** Post-Conditions: Returns positive int <= limit
*********************************************************************/
int getPosIntInput(int limit)
{
	int i;
	std::cin >> i;
	
	/* retrieve an int >= 0 */
	while (std::cin.fail() || i <= 0 || i > limit)
	{
		std::cout << "Invalid input. Please enter a positive integer <= " << limit << "." << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> i;
	}

	std::cin.ignore(1000, '\n');
	return i;
	/* use of cin.fail() inspired by
	** http://stackoverflow.com/questions/18728754/checking-input-value-is-an-integer */
}


/*********************************************************************
** Function: getNonNegDoubleInput()
** Description: Prompts user for a non-negative double, ignoring additional
** characters after the double, or re-prompting the user if invalid
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the validated double
*********************************************************************/
double getNonNegDoubleInput()
{
	double d;
	std::cin >> d;

	/* retrieve an int >= 0 */
	while (std::cin.fail() || d < 0)
	{
		std::cout << "Invalid input. Please enter a non-negative double." << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> d;
	}

	std::cin.ignore(1000, '\n');
	return d;
}


/*********************************************************************
** Function: isAlphaNumPunctString(std::string s)
** Description: Checks that the string contains only alphanumeric,
** space, or punctuation characters
** Parameters: string s
** Pre-Conditions: None
** Post-Conditions: true if string contains alphanumeric, space, and 
** punctuation characters only, otherwise returns false
*********************************************************************/
bool isAlphaNumPunctString(std::string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if ((!isalnum(s[i])) && (!ispunct(s[i])) && (!isspace(s[i])))
		{
			std::cout << "Problem with character " << s[i] << " @ " << i << std::endl;
			return false;
		}
	}
	return true;
}


/*********************************************************************
** Function: getAlphaNumPunctString()
** Description: Loops to prompts user for and validate a string that 
** is alphanumeric and can include punctuation and spaces
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the validated string
*********************************************************************/
std::string getAlphaNumPunctString()
{
	std::string s;
	std::getline(std::cin, s);

	while (std::cin.fail() || !isAlphaNumPunctString(s))
	{
		std::cout << "Invalid input. Please enter alphanumeric characters or punctuation." << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::getline(std::cin, s);
	}
	return s;
}


/*** STRING MANIPULATION FUNCTIONS ***/


/*********************************************************************
** Function: makeLower(string s)
** Description: Returns the string in lowercase
** Parameters: string s
** Pre-Conditions: None
** Post-Conditions: Returns lowercase string
*********************************************************************/
std::string makeLower(std::string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
	return s;
}


/*** MATH FUNCTIONS ***/


/*********************************************************************
** Function: roundDouble(double d, int precision)
** Description: Returns the double rounded to specified points of precision
** Parameters: double d, int precision
** Pre-Conditions: None
** Post-Conditions: Returns rounded double
*********************************************************************/
double roundDouble(double d, int precision)
{
	return (round(d * pow(10, precision)) / pow(10, precision));
}