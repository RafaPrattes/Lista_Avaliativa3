#include <stdio.h>
#include <string.h>

void decimalParaBinario(int decimal, char binario[]) {
    int i = 0;

    if (decimal == 0) {
        binario[i++] = '0';
    } else {
        while (decimal > 0) {
            binario[i++] = (decimal % 2) + '0';
            decimal /= 2;
        }
    }

    binario[i] = '\0';

    int inicio = 0;
    int fim = i - 1;
    while (inicio < fim) {
        char temp = binario[inicio];
        binario[inicio] = binario[fim];
        binario[fim] = temp;
        inicio++;
        fim--;
    }
}

int valorRomano(char c) {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int romanoParaInt(char *romano) {
    int resultado = 0;
    int tamanho = strlen(romano);

    for (int i = 0; i < tamanho; i++) {
        if (i < tamanho - 1 && valorRomano(romano[i]) < valorRomano(romano[i + 1])) {
            resultado -= valorRomano(romano[i]);
        } else {
            resultado += valorRomano(romano[i]);
        }
    }

    return resultado;
}

int main() {
    char entrada[13];
    char binario[32];

    scanf("%s", entrada);

    int valorDecimal = romanoParaInt(entrada);

    printf("%s na base 2: ", entrada);
    decimalParaBinario(valorDecimal, binario);
    printf("%s\n", binario);

    printf("%s na base 10:  %d\n", entrada, valorDecimal);

    printf("%s na base 16:  %X\n", entrada, valorDecimal);

    return 0;
}
