///////////////
// Libraries //
///////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>
#include <stdbool.h>

////////////////
// Structures //
////////////////

typedef struct password {
        char *password;
        bool upperCase;
        bool lowerCase;
        bool numbers;
        bool specialC;
        int length;
        bool appearList;
} Pass;

////////////////
// Prototypes //
////////////////

extern void __HELP();
extern void setResultsREGEX(Pass *key);
extern void initREGEX(char *compare, regex_t *test);
extern bool execREGEX(char *password, regex_t *test);
extern void validateCharacters(Pass *key);
extern void searchList(Pass *key);
extern void getResults(Pass *key);
extern float getAverage(Pass *key, float length);
extern void getStatus(float average, char *status);
extern void consecutiveLetters(Pass *key);

///////////////
// Constants //
///////////////
