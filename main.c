#include "headers.h"

int main(int argc, char *argv[]) {
        Pass key;

        if (argc == 5 && strcmp(argv[1],"-p") == 0 && strcmp(argv[3],"-u") == 0) {
                key.password = argv[2];
                key.user = argv[4];

                setResultsREGEX(&key);
                validateCharacters(&key);
                compareWithUser(&key);
                searchList(&key);
                getResults(&key);

        } else {
                __HELP();
        }

        printf("\nBye!!!\n\n\n");

        return 0;
}
