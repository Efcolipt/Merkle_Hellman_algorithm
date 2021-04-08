#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



void decryption(int m, int n, int* closeKey) {
    int index = 7, counter = 0, counterAnswere = 0;
    int n1 = 1, quanity = 0, i = 0;
    int cipher[100] = { 0 }, result[100];
    int binaryIndexs[8] = { 0 };
    int resultAnswere[100] = { 0 };
    while (n * n1 % m != 1) n1++;
    printf("\nEnter quanity Cipher:\n");
    scanf("%d", &quanity);
    printf("Enter ciphers:\n");
    for (i = 0; i < quanity; i++) scanf("%d", &cipher[i]);
    for (i = 0; i < quanity; i++) {
        result[i] = cipher[i] * n1 % m;
        counter = 0; index = 7; memset(binaryIndexs, 0, sizeof binaryIndexs);
        while (result[i] > 0) {
            while (closeKey[index] > result[i]) index--;
            result[i] -= closeKey[index];
            binaryIndexs[counter] = 7 - index;
            resultAnswere[counterAnswere] += pow(2, binaryIndexs[counter]);
            index = 7; counter++;
        }
        printf("Result: %c", char(resultAnswere[counterAnswere]));
        counterAnswere++;
    }
}



void encryption(int* openKey) {
    int result = 0;
    char binaryWord[1000] = { 0 }, word[1000] = { 0 };
    printf("\nEnter word.\n");
    scanf("%s", &word);
    for (int i = 0; word[i] != '\0'; i++) {
        result = 0;
        for (int b = 7, v = 0; b >= 0; --b, v++) binaryWord[v] = (word[i] & (1 << b)) ? '1' : '0';
        for (int j = 0; j < 8; j++)  if (binaryWord[j] == '1') result += openKey[j];
        printf("Cipher program: %d\n", result);
    }
}


void createOpenKey(int* closeKey, int m, int n, int* openKey) {

    printf("Private key: ");
    for (int i = 0; i < 8; i++) printf("%d, ", closeKey[i]);

    printf("\nPublic key: ");
    for (int i = 0; i < 8; i++)
    {
        openKey[i] = closeKey[i] * n % m;
        printf("%d, ", openKey[i]);
    }
}


int main(void)
{
    int  m = 335, n = 19;
    int closeKey[8] = { 1, 3, 5, 10, 21, 42, 84, 167 }, openKey[8] = { 0 }, a = 0;
    createOpenKey(closeKey, m, n, openKey);
    encryption(openKey);
    decryption(m, n, closeKey);

    return 0;
}
