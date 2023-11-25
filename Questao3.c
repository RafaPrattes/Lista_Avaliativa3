#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int formatoPlacaValido(char *placa) {
    return (strlen(placa) == 8 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
            isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7]) &&
            placa[3] == '-') ||
           (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
            isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]));
}

int verificaRestricaoCirculacao(char *placa, char *diaSemana) {
    int ultimoDigito = placa[strlen(placa) - 1] - '0';

    if(strcmp(diaSemana, "SEGUNDA-FEIRA") == 0) {
        return ultimoDigito != 0 && ultimoDigito != 1;
    } else if(strcmp(diaSemana, "TERCA-FEIRA") == 0) {
        return ultimoDigito != 2 && ultimoDigito != 3;
    } else if(strcmp(diaSemana, "QUARTA-FEIRA") == 0) {
        return ultimoDigito != 4 && ultimoDigito != 5;
    } else if(strcmp(diaSemana, "QUINTA-FEIRA") == 0) {
        return ultimoDigito != 6 && ultimoDigito != 7;
    } else if(strcmp(diaSemana, "SEXTA-FEIRA") == 0) {
        return ultimoDigito != 8 && ultimoDigito != 9;
    } else if(strcmp(diaSemana, "SABADO") == 0 || strcmp(diaSemana, "DOMINGO") == 0) {
        return -1;
    } else {
        return -2;
    }
}

void converterMinusculo(char *diaSemana) {
    for (int i = 0; i < strlen(diaSemana); i++) {
        diaSemana[i] = tolower(diaSemana[i]);
    }
}

int main() {
    char placa[9];
    char diaSemana[30];

    scanf("%s", placa);
    scanf(" %s", diaSemana);

    if (formatoPlacaValido(placa)) {
        int resultadoRestricao = verificaRestricaoCirculacao(placa, diaSemana);

        switch (resultadoRestricao) {
            case 1:
                converterMinusculo(diaSemana);
                printf("%s pode circular %s\n", placa, diaSemana);
                break;
            case 0:
                converterMinusculo(diaSemana);
                printf("%s nao pode circular %s\n", placa, diaSemana);
                break;
            case -1:
                printf("Nao ha proibicao no fim de semana\n");
                break;
            case -2:
                printf("Dia da semana invalido\n");
                break;
        }
    } else {
        printf("Placa invalida\n");
        if(verificaRestricaoCirculacao(placa, diaSemana) == -2) {
            printf("Dia da semana invalido\n");
        }
    }

    return 0;
}
