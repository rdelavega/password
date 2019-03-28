#include "headers.h"

void validateCharacters(Pass *key) {
        int length = 0;
        char *pass = key->password;
        bool res = false;

        length = strlen(pass);
        key->length = length;

        for (int i = 0; i < length; i++) {
                if (!isalnum(pass[i])) {
                        res = true;
                }
        }

        consecutiveLetters(key);

        // printf("%s\n", res ? "true" : "false");
        key->specialC = res;
}

void consecutiveLetters(Pass *key) {
        int length = strlen(key->password);
        char *pass = key->password;

        for (int i = 0; i < length; i++) {
                if (isalpha(pass[i]) != 0) {
                        validateChar(i, pass, key);
                } else if (isdigit(pass[i]) != 0) {
                        validateNum(i, pass, key);
                }
        }

}

void validateNum(int i, char *pass, Pass *key) {
        int digit = 0, last = 0, next = 0;

        digit = pass[i] - 48;
        if (isdigit(pass[i-1]) || isdigit(pass[i+1])) {
                last = pass[i-1] - 48;
                next = pass[i+1] - 48;

                if (digit == last || digit == next) {
                        key->repetitiveNum = true;
                }

                if ((digit == (last + 1) || digit == (next - 1)) ||
                    (digit == (last - 1) || digit == (next + 1))) {
                        key->consecutiveNum = true;
                }
        }
}

void validateChar(int i, char *pass, Pass *key) {
        char ctemp = '\0', clast = '\0', cnext = '\0';

        ctemp = pass[i];
        if (isalpha(pass[i-1]) || isalpha(pass[i+1])) {
                clast = pass[i-1];
                cnext = pass[i+1];

                if (ctemp == clast || ctemp == cnext) {
                        key->repetitiveChar = true;
                }

                if ((ctemp == (clast + 1) || ctemp == (cnext - 1))
                    /*||(ctemp == (clast - 1) || ctemp == (cnext + 1))*/) {
                        key->consecutiveChar = true;
                }
        }
}

void compareWithUser(Pass *key) {
        int length = strlen(key->password);
        char temp[4];
        char *pass = key->password;
        char *p;

        if (length >= 4) {
                for (int i = 0; i < (length - 2); i++) {
                        if (pass[i + 3]) {
                                for (int j = 0; j < 4; j++) {
                                        temp[j] = pass[i + j];
                                }

                                p = strstr (key->user,temp);

                                if (p || strcmp(key->user,key->password) == 0) {
                                        key->related = true;
                                }
                        }
                }
        }
}
