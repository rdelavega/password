#include "headers.h"

/***********************************************************************
* Validar que se hayan introducido caracteres especiales, teniendo en *
* cuenta que hay caracteres no alfa-numericos                         *
*                                                                     *
* @param key struct password                                          *
***********************************************************************/

void validateCharacters(Pass *key) {
        int length = 0;
        char *pass = key->password;
        bool res = false;

        length = strlen(pass);
        key->length = length;

        for (int i = 0; i < length; i++) {
                if (!isalnum(pass[i])) {//  Alfanumericos
                        res = true;
                }
        }

        consecutiveLetters(key);

        // printf("%s\n", res ? "true" : "false");
        key->specialC = res;
}

/*********************************************************************************
* Handler de caracteres consecutivos, separa los caracteres por letra o digito, *
* para su siguiente comaracion.                                                 *
*                                                                               *
* @param key struct password                                                    *
*********************************************************************************/

void consecutiveLetters(Pass *key) {
        int length = strlen(key->password);
        char *pass = key->password;

        for (int i = 0; i < length; i++) {
                if (isalpha(pass[i]) != 0) {//  Letras
                        validateChar(i, pass, key);
                } else if (isdigit(pass[i]) != 0) {// Numeros
                        validateNum(i, pass, key);
                }
        }

}

/****************************************************************************
* Compara una posicion de la contraseña numerica, asi como el valor en la  *
* posicion siguiente y en la anterior, detectado repeticiones o numeros    *
* consecutivos.                                                            *
*                                                                          *
* @param i     posicion                                                    *
* @param pass  contraseña                                                  *
* @param key   struct password                                             *
****************************************************************************/

void validateNum(int i, char *pass, Pass *key) {
        int digit = 0, last = 0, next = 0;

        digit = pass[i] - 48;
        if (isdigit(pass[i-1]) || isdigit(pass[i+1])) {
                last = pass[i-1] - 48;
                next = pass[i+1] - 48;

                if (digit == last || digit == next) {// Repetidos
                        key->repetitiveNum = true;
                }

                if ((digit == (last + 1) || digit == (next - 1)) ||
                    (digit == (last - 1) || digit == (next + 1))) {// Consecutivos
                        key->consecutiveNum = true;
                }
        }
}

/*****************************************************************************
* Compara una posicion de la contraseña, asi como el valor en la posicion   *
* siguiente y en la anterior, detectado repeticiones o letras consecutivos. *
*                                                                           *
* @param i     posicion                                                     *
* @param pass  contraseña                                                   *
* @param key   struct password                                              *
*****************************************************************************/

void validateChar(int i, char *pass, Pass *key) {
        char ctemp = '\0', clast = '\0', cnext = '\0';

        ctemp = pass[i];
        if (isalpha(pass[i-1]) || isalpha(pass[i+1])) {
                clast = pass[i-1];
                cnext = pass[i+1];

                if (ctemp == clast || ctemp == cnext) {// Repetidos
                        key->repetitiveChar = true;
                }

                if ((ctemp == (clast + 1) || ctemp == (cnext - 1))
                    /*||(ctemp == (clast - 1) || ctemp == (cnext + 1))*/) {// Consecutivos
                        key->consecutiveChar = true;
                }
        }
}

/******************************************************************************
* Divide la contraseña introducuida en bloques de 4 caracteres, para despues *
* verificar que dichos bloques no esten contenidos en el id de usuario para  *
* evitar una relacion entre id y contraseña                                  *
*                                                                            *
* @param key   struct password                                               *
******************************************************************************/

void compareWithUser(Pass *key) {
        int length = strlen(key->password);
        char temp[4];
        char *pass = key->password;
        char *p;

        if (length >= 4) {
                for (int i = 0; i < (length - 2); i++) {
                        if (pass[i + 3]) {
                                for (int j = 0; j < 4; j++) {// Crear bloques
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
