#ifndef UTILITYLIB_HPP
#define UTILITYLIB_HPP

#include <string>

/* display */
void clearScreen();
void waitMillisecs(int millisec);
std::string formatDecimal(double d, int precision);

/* input validation */
bool getYesNo();
bool getSimpleTrigger(std::string prompt, std::string desc, std::string success);
int getPosIntInput();
int getPosIntInput(int limit);
double getNonNegDoubleInput();
bool isAlphaNumPunctString(std::string s);
std::string getAlphaNumPunctString();

/* string manipulation */
std::string makeLower(std::string s);

/* math */
double roundDouble(double d, int precision);

#endif
