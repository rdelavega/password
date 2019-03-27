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
        int c = 0;

        char *pass = key->password;

        for(int i=0; i<strlen(pass); i++) {
                if(pass[i]==pass[i+1]) {
                        printf("%c is consecutive\n",pass[i]);
                        c++;
                }
        }

        if(c==0) {
                printf("No consecutive letters");
        }
}
