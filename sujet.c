#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sujet.h"

int strip_extrema(int *array, int laps);
int normaliseCapteur(int *valCapteur);

int main(void){
    int initialCapteur[8] = { 2, 56, 180, 60, 10, 1020, 65, 55 };
    
    int *valCapteur;
    valCapteur = (int *)malloc(9*sizeof(int));
    int moyenne;

    for(int i=0 ; i<8 ; i++)
        *(valCapteur+i) = initialCapteur[i];
    *(valCapteur+8) = -__INT_MAX__;

    strip_extrema(valCapteur,2);

    long int j;
    unsigned long duree;
    struct timeval debutCalcul, finCalcul;

    // Heure debut du calcul
    gettimeofday(&debutCalcul,NULL);

    // Refaire le calcul 10000 fois pour augmenter la durée de calcul
    for( j = 0; j < __INT64_MAX__; j++) {
        moyenne = normaliseCapteur(valCapteur);
    }

    // Heure fin du calcul
    gettimeofday(&finCalcul,NULL);

    printf("moyenne %d\n", moyenne);

    duree = ((finCalcul.tv_sec - debutCalcul.tv_sec) * 1000000) + (finCalcul.tv_usec - debutCalcul.tv_usec);
    printf( "Durée %ld ms\n", duree );

    free(valCapteur);

    return EXIT_SUCCESS;
}

int normaliseCapteur(int *valCapteur){
    int i = 0;
    int total=0;
    int moyenne;

    total = 0;
    while(valCapteur[i] != -__INT_MAX__){
        total += valCapteur[i];
        i++;
    }
    moyenne = total / i;

    return(moyenne);
}

int strip_extrema(int *array, int laps){
    for(int i=0 ; i<laps ; i++){
        int *maxi = find_max_addr(array);
        int j = 0;
        while(*(maxi+j) != -__INT_MAX__){
            *(maxi+j) = *(maxi+j+1);
            j++;
        }
    }
    for(int i=0 ; i<laps ; i++){
        int *mini = find_min_addr(array);
        int j = 0;
        while(*(mini+j) != -__INT_MAX__){
            *(mini+j) = *(mini+j+1);
            j++;
        }

    }
    return EXIT_SUCCESS;
}