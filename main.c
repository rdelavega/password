#include "headers.h"

int main(int argc, char *argv[]) {
        Pass key;

        if (argc == 3 && strcmp(argv[1],"-p") == 0) {
                key.password = argv[2];

                setResultsREGEX(&key);
                validateCharacters(&key);
                searchList(&key);
                getResults(&key);

        } else {
                __HELP();
        }

        printf("\nBye!!!\n\n\n");

        return 0;
}
