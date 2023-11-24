#include <stdio.h>
#include <string.h>
#include <ctype.h>

int placaValida(char placa[]) {
    if (strlen(placa) != 7 && strlen(placa) != 8) {
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        if (!isalpha(placa[i])) {
            return 0;
        }
    }

    if (placa[3] != '-' || !isdigit(placa[4]) || !isdigit(placa[5]) || !isdigit(placa[6])) {
        return 0;
    }

    if (strlen(placa) == 8 && !isdigit(placa[7])) {
        return 0;
    }

    return 1;
}

int diaSemanaValido(char diaSemana[]) {
    char diasValidos[7][15] = {"segunda-feira", "terca-feira", "quarta-feira", "quinta-feira", "sexta-feira", "sabado", "domingo"};

    for (int i = 0; i < 7; i++) {
        if (strcasecmp(diaSemana, diasValidos[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int podeCircular(char letraDia, int ultimoDigito) {
    switch (letraDia) {
        case 's':
            return (ultimoDigito != 0 && ultimoDigito != 1);
        case 't':
            return (ultimoDigito != 2 && ultimoDigito != 3);
        case 'q':
            return (ultimoDigito != 4 && ultimoDigito != 5);
        default:
            return 1;
    }
}

int main() {
    char placa[9];
    char diaSemana[15];

    scanf("%s %s", placa, diaSemana);

    for (int i = 0; diaSemana[i]; i++) {
        diaSemana[i] = tolower(diaSemana[i]);
    }

    if (!placaValida(placa)) {
        printf("Placa invalida\n");
    } else if (!diaSemanaValido(diaSemana)) {
        printf("Dia da semana invalido\n");
    } else {
        int ultimoDigito = placa[strlen(placa) - 1] - '0';

        if (strcasecmp(diaSemana, "sabado") == 0 || strcasecmp(diaSemana, "domingo") == 0) {
            printf("Nao ha proibicao no fim de semana\n");
        } else {
            char letraDia = tolower(diaSemana[0]);

            if (podeCircular(letraDia, ultimoDigito)) {
                printf("%s pode circular %s\n", placa, diaSemana);
            } else {
                printf("%s nao pode circular %s\n", placa, diaSemana);
            }
        }
    }

    return 0;
}
