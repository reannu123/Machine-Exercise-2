#include <stdio.h>
#include <string.h>

int CharBits[256];
int Blocks = 1;
int oldCipherBlocks[4][64];
int CipherBlocks[4][64];
int oldFPText[4][64];
int FPText[4][64];


int main(){
    char pq[33];
    char e[65];
    char loops[65];

    scanf("%[^\n]", pq);
    getchar();                      // get newline
    scanf("%[^\n]", e);
    getchar();                      // get newline
    scanf("%[^\n]", loops);
    getchar();

    char * token = strtok(pq, " ");
    while (token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }


    return 0;
}