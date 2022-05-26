#include <stdio.h>
#include <string.h>
#include <math.h>
// #include <gmp.h>

long get_d(long e, long phi){
    for (int i = 1; i < 99999999; i++){
        if ((e * i) % phi == 1){
            return i;
        }
    }
}

// NEED TO STORE pow() VALUES IN VERY BIG INTEGER
long encrypt(long m, long e, long n){
    long encrypted = pow(11029, 293);
    printf("Encrypted: %ld\n", encrypted);
    long answer = encrypted % n;
    return answer;
}

// NEED TO STORE pow() VALUES IN VERY BIG INTEGER
long decrypt(long c, long d, long n){
    long decrypted = pow(c, d);
    long answer = decrypted % n;
    return answer;
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
            printf("%ld\n", encrypt(m, e, n));
        }
        else if(!strcmp(action,"decrypt")){     // decrypt if action is decrypt
            printf("%ld\n", decrypt(m, d, n));
        }
    }

    return 0;
}