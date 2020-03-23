#include "headers.h"

/*******************************************************************************
* Abre un archivo extraido de: https://raw.githubusercontent.com/danielmiessl *
* er/SecLists/master/Passwords/Common-Credentials/10-million-password-list-to *
* p-1000000.txt, se comparara que la contraseña introducida, no este en la    *
* lista de contraseñas comunes.                                               *
*                                                                             *
* @param key   struct password                                                *
*******************************************************************************/

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
        length = getline(&buffer, &buffer_size, file);// Leer linea completa

        strtok(buffer, "\n");// Eliminar salto de,linea

        if (strcmp(key->password, buffer) == 0 /*|| strstr(key->password, buffer) != 0*/) {
            key->appearList = true;
        }
    }

    free(buffer);
    buffer = NULL;

    fclose(file);

    // printf("%s\n", key->appearList ? "true" : "false");
}
