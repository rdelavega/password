#include "headers.h"

void searchList(Pass *key) {
        char *buffer = NULL;
        size_t buffer_size = 0;
        ssize_t length;

        FILE *file = fopen("passwordList.txt", "r");

        if (!file) {
                fprintf(stderr, "Error archivo\n");
        }

        length = getline(&buffer, &buffer_size, file);

        while (length >= 0) {
                length = getline(&buffer,&buffer_size, file);

                strtok(buffer, "\n");

                if (strcmp(key->password, buffer) == 0 /*|| strstr(key->password, buffer) != 0*/) {
                        key->appearList = true;
                }
        }

        free(buffer);
        buffer = NULL;

        fclose(file);

        // printf("%s\n", key->appearList ? "true" : "false");
}
