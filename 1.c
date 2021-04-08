#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int dec2bin(int num)
{
    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}




void decryption(int m, int n,int* closeKey){
    int index = 7, counter = 0,counterAnswere = 0;
    int n1 = 1, quanity = 0, i = 0;
    int cipher[100] = {0}, result[100];
    char binaryIndexs[8] = {0};
    int resultAnswere[100] = {0};
    while (n * n1 % m != 1) n1++;
    printf("\nEnter quanity Cipher:\n");
    scanf("%d", &quanity);
    printf("Enter ciphers:\n");
    for (i = 0; i < quanity; i++) scanf("%d", &cipher[i]);
    for (i = 0; i < quanity; i++) {
        result[i] = cipher[i] * n1 % m;
        counter = 0; index = 7; memset(binaryIndexs, 0 , sizeof binaryIndexs);
        while(result[i] > 0){
            while(closeKey[index] > result[i]) index--;
            result[i] -= closeKey[index];
            binaryIndexs[counter++] = index;
            index = 7;
        }
        for (size_t v = 0; binaryIndexs[v] != '\0'; v++) resultAnswere[counterAnswere] +=  dec2bin(pow(2, binaryIndexs[v]));
        printf("%d\n",resultAnswere[counterAnswere]);
        counterAnswere++;
    }
}



void encryption(int *openKey){
    int result = 0;
    char binaryWord[1000] = {0}, word[1000] = {0};
    printf("\nEnter word.\n");
    scanf("%s", &word);
    for (int i = 0; word[i] != '\0'; i++) {
        result = 0;
        for (int b = 7,v = 0; b >= 0; --b, v++) binaryWord[v] = (word[i] & (1 << b)) ? '1' : '0';
        for (int j = 0; j < 8; j++)  if (binaryWord[j] == '1') result += openKey[j];
        printf("Cipher program: %d\n", result);
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
        case 2: decryption(m, n, closeKey); break;
    }

    return 0;
}
