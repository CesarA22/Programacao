/*
Artur Henrique Pagno - 21013037
Carlos Eduardo Fontes Camacho  - 21008649
Cesar Augusto Camote Inocencio - 20018446
Felipe de Moura Tayar - 201019634
João Victor Moreira Vidal - 19291384
Patrick Pimentel Corrêa Leite - 21007850

Opções: 1, 2 e 3.
*/



#include <stdio.h>
#include <stdlib.h>


int multiplicacao(int num1, int num2) {
    if (num2 == 0) {
        return 0;
    } else {
        return num1 + multiplicacao(num1, num2 - 1);
    }
}

int soma(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    } else {
        return soma(num1 + 1, num2 - 1);
    }
}

float calculo(int num) {
    if (num == 1) {
        return 1;
    } else {
        return (float) 1 / num + calculo(num - 1);
    }
}

int main() {
    int opcao;
    do {
        printf("\n\n\t\t\t\tMENU\n");
        printf("[1] multiplicação de dois números naturais, através de somas sucessivas\n");
        printf("[2] soma de dois números naturais, através de incrementos sucessivos\n");
        printf("[3] o cálculo de 1+ ½+ 1/3+ ¼ +..... + 1/N\n");
        printf("[4] encerrar\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int num1, num2;
                printf("Digite o primeiro número: ");
                scanf("%d", &num1);
                printf("Digite o segundo número: ");
                scanf("%d", &num2);

                int resultado = multiplicacao(num1, num2);

                printf("O resultado da multiplicação é: %d\n", resultado);
                break;
            }
            case 2: {
                int num1, num2;
                printf("Digite o primeiro número: ");
                scanf("%d", &num1);
                printf("Digite o segundo número: ");
                scanf("%d", &num2);

                int resultado = soma(num1, num2);

                printf("O resultado da soma é: %d\n", resultado);
                break;
            }
            case 3: {
                int num;
                printf("Digite o valor de N: ");
                scanf("%d", &num);

                float resultado = calculo(num);

                printf("O resultado do cálculo é: %.2f\n", resultado);
                break;
            }
            case 4: {
                printf("Programa encerrado!\n");
                break;
            }
            default: {
                printf("Opção inválida!\n");
            }
        }

    } while (opcao != 4);

    return 0;
}