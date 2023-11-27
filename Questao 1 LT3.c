#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int value(char r) {
    if (r == 'I' || r == 'i')
        return 1;
    if (r == 'V' || r == 'v')
        return 5;
    if (r == 'X' || r == 'x')
        return 10;
    if (r == 'L' || r == 'l')
        return 50;
    if (r == 'C' || r == 'c')
        return 100;
    if (r == 'D' || r == 'd')
        return 500;
    if (r == 'M' || r == 'm')
        return 1000;
    return -1;
}

int romanoPraDecimal(char *num) {
    
    int res = 0;
    int i;

    for (i = 0; i < strlen(num); i++) {
        int s1 = value(num[i]);

        if (i + 1 < strlen(num)) {
            int s2 = value(num[i + 1]);

            if (s1 >= s2) {
                res = res + s1;
            } else {
                res = res + s2 - s1;
                i++;
            }
        } else {
            res = res + s1;
            i++;
        }
    }
    return res;
}

void printBinario(int n) {
    if (n > 1) {
        printBinario(n / 2);
    }
    printf("%d", n % 2);
}

void printHexadecimal(int n) {
    char *hexaDeciNum = (char *)malloc(sizeof(char) * 100);
    int i = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        } else {
            hexaDeciNum[i] = temp + 87; //
            i++;
        }
        n = n / 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexaDeciNum[j]);
    }
    free(hexaDeciNum);
}

int main() {
    char numRomano[100];

    scanf("%s", numRomano);

    int decimal = romanoPraDecimal(numRomano);

    printf("%s na base 2: ", numRomano);
    printBinario(decimal);
    printf("\n");
    
    printf("%s na base 10: %d\n", numRomano, decimal);

    printf("%s na base 16: ", numRomano);
    printHexadecimal(decimal);
    printf("\n");

    return 0;
}