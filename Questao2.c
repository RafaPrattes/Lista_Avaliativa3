#include <stdio.h>

void simularInvestimento(int numMeses, double aporteMensal, double taxaJuros) {
    double montanteTotal = 0;

    for (int mes = 1; mes <= numMeses; mes++) {
        montanteTotal = (montanteTotal + aporteMensal) * (1 + taxaJuros);
        printf("Montante ao fim do mes %d: R$ %.2f\n", mes, montanteTotal);
    }
}

int main() {
    int numMeses;
    double aporteMensal, taxaJuros;

    scanf("%d", &numMeses);

    scanf("%lf", &aporteMensal);

    scanf("%lf", &taxaJuros);

    if (1 <= numMeses && numMeses <= 240 && 1 <= aporteMensal && aporteMensal <= 5000 && 0.01 <= taxaJuros && taxaJuros <= 0.2) {
        simularInvestimento(numMeses, aporteMensal, taxaJuros);
    } else {
        printf("Valores de entrada fora das faixas especificadas.\n");
    }

    return 0;
}
    }

    return 0;
}
