#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


void decryption(int m, int n){
    int n1 = 1, i = 0;
    int cipher[100] = {0}, result[100];
    while (n * n1 % m != 1) n1++;
    printf("Ciphers (-1 to stop typing):\n");
    while(1){
        scanf("%d", &cipher[i]);
        if (cipher[i] == -1) break;
        i++;
    }

    for (i = 0; cipher[i] != -1; i++) {
        result[i] = cipher[i] * n1 % m;
        printf("Weight in %d row: %d\n", i + 1, result[i]);
    }
}


void encryption(int *openKey){
    int result = 0,  num = 0, j = 0, i = 0, quanity = 0,temp = 0;
    int binaryWord[1000];
    printf("\nEnter quanity binary.\n");
    scanf("%d", &quanity);
    printf("\nEnter binary.\n");
    for(int i = 0, j = 0; i < 1000; i++){
        if (temp == (quanity * 8))break;
        scanf("%d", &binaryWord[i]);
        if (binaryWord[i] == 1) result += openKey[j];
        temp++; j++;
        if (j == 8){
            printf("Cipher program: %d\n", result);
            j = result = 0;
        }
    }
}


void createOpenKey(int *closeKey, int m, int n, int* openKey){

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
    int closeKey[8] = { 1, 3, 5, 10, 21, 42, 84, 167 }, openKey[8] = {0}, a = 0;
    printf("Encrypt text (1) or Decrypt text (2): ");
    scanf("%d", &a);
    createOpenKey(closeKey, m, n, openKey);
    switch (a){
        case 1: encryption(openKey); break;
        case 2: decryption(m, n); break;
    }

    return 0;
}
