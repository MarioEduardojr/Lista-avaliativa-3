#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarPlaca(char *placa) {
    int i;

    if (strlen(placa) == 8 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
        placa[3] == '-' && isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7])) {
        return 1;
    }

    if (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
        isalpha(placa[3]) && isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6])) {
        return 1;
    }

    return 0;
}

int main() {
    char placa[10], diaSemana[20];

    printf("Digite a placa do veiculo: ");
    scanf("%s", placa);

    if (!validarPlaca(placa)) {
        printf("Placa invalida\n");
        return 1;
    }

    printf("Digite o dia da semana: ");
    scanf("%s", diaSemana);

    for (int i = 0; diaSemana[i]; i++) {
        diaSemana[i] = toupper(diaSemana[i]);
    }

    if (strcmp(diaSemana, "SEGUNDA-FEIRA") == 0 || strcmp(diaSemana, "TERCA-FEIRA") == 0 ||
        strcmp(diaSemana, "QUARTA-FEIRA") == 0 || strcmp(diaSemana, "QUINTA-FEIRA") == 0 ||
        strcmp(diaSemana, "SEXTA-FEIRA") == 0 || strcmp(diaSemana, "SABADO") == 0 ||
        strcmp(diaSemana, "DOMINGO") == 0) {

        int ultimoDigito = placa[strlen(placa) - 1] - '0';

        switch (ultimoDigito) {
            case 0:
            case 1:
                if (strcmp(diaSemana, "SEGUNDA-FEIRA") == 0) {
                    printf("Pode circular.\n");
                } else {
                    printf("Nao pode circular.\n");
                }
                break;
            case 2:
            case 3:
                if (strcmp(diaSemana, "TERCA-FEIRA") == 0) {
                    printf("Pode circular.\n");
                } else {
                    printf("Nao pode circular.\n");
                }
                break;
            case 4:
            case 5:
                if (strcmp(diaSemana, "QUARTA-FEIRA") == 0) {
                    printf("Pode circular.\n");
                } else {
                    printf("Nao pode circular.\n");
                }
                break;
            case 6:
            case 7:
                if (strcmp(diaSemana, "QUINTA-FEIRA") == 0) {
                    printf("Pode circular.\n");
                } else {
                    printf("Nao pode circular.\n");
                }
                break;
            case 8:
            case 9:
                if (strcmp(diaSemana, "SEXTA-FEIRA") == 0) {
                    printf("Pode circular.\n");
                } else {
                    printf("Nao pode circular.\n");
                }
                break;
        }
    } else {
        printf("Dia da semana invalido.\n");
    }

    return 0;
}