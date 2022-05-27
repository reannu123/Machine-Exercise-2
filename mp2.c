#include <stdio.h>
#include <string.h>
#include <math.h>


long modExpo(long base, long exp, long mod){
    long result = 1;
    while(exp > 0){
        if(exp % 2 == 1){
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

long get_d(long e, long phi){
    for (int i = 1; i < 99999999; i++){
        if ((e * i) % phi == 1){
            return i;
        }
    }
}



int main(){
    char pq[33];
    char e_input[65];
    char loops[65];

    scanf("%[^\n]", pq);            // get p and q in single string
    getchar();

    char * token = strtok(pq, " "); // get p
    long p = atoi(token);
    token = strtok(NULL, " ");      // get q
    long q = atoi(token);           

                          
    scanf("%[^\n]", e_input);       // get e
    getchar();                      
    long e = atoi(e_input);         // convert to int

    scanf("%[^\n]", loops);         // get number of actions (loops)
    getchar();

    
    long n = p*q;                   // n = pq
    long phi = (p-1)*(q-1);         // phi = (p-1)(q-1)

    long d = get_d(e, phi);         // get d


    for(int i = 0; i < atoi(loops); i++){
        char input[65];
        scanf("%[^\n]", input);     // get message and action
        getchar();

        char * action = strtok(input, " ");
        char * token = strtok(NULL, " ");

        long m = atoi(token);       // convert m to int


        if(!strcmp(action,"encrypt")){          // encrypt if action is encrypt
            printf("%ld\n", modExpo(m, e, n));
        }
        else if(!strcmp(action,"decrypt")){     // decrypt if action is decrypt
            printf("%ld\n", modExpo(m, d, n));
        }
    }

    return 0;
}