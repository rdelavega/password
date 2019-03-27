#include "headers.h"

void setResultsREGEX(Pass *key) {
        char *compare[3] = {
                "([a-z])",
                "([A-Z])",
                "([0-9])"
        };
        regex_t test;
        bool res = false;

        for (int i = 0; i < 3; i++) {
                initREGEX(compare[i], &test);
                res = execREGEX(key->password, &test);
                // printf("%s\n", res ? "true" : "false");

                switch (i) {
                case 0:
                        key->lowerCase = res;
                        break;
                case 1:
                        key->upperCase = res;
                        break;
                case 2:
                        key->numbers = res;
                        break;
                }

                regfree(&test);
        }
}

void initREGEX(char *compare, regex_t *test) {
        int status = regcomp (test, compare, REG_EXTENDED|REG_NEWLINE);

        if (status != 0) {
                char error_message[0x1000];
                regerror (status, test, error_message, 0x1000);
                printf ("Regex error compiling '%s': %s\n",
                        compare, error_message);
        }

}

bool execREGEX(char *password, regex_t *test) {
        const char *pass = password;
        const int maxMatches = 10;
        regmatch_t match[maxMatches];
        bool contains = false;
        int in = 0, didMatch = 0;

        while (in == 0) {
                didMatch = regexec (test, pass, maxMatches, match, 0);

                if (didMatch) {
                        in = 1;
                        contains = false;
                } else {
                        in = 1;
                        contains = true;
                }
        }

        return contains;
}
