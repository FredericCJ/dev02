#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sujet.h"

int *strip_extrema(int *array, int laps);
int normaliseCapteur(int *valCapteur);

int main(void){
    int valCapteur[8] = { 2, 56, 180, 60, 10, 1020, 65, 55 };
    *(valCapteur+8) = '\0';
    int moyenne;

    strip_extrema(valCapteur,2);

    int j;
    unsigned long duree;
    struct timeval debutCalcul, finCalcul;

    // Heure debut du calcul
    gettimeofday(&debutCalcul,NULL);

    // Refaire le calcul 10000 fois pour augmenter la durée de calcul
    for( j = 0; j < 10000; j++) {
        moyenne = normaliseCapteur(valCapteur);
    }

    // Heure fin du calcul
    gettimeofday(&finCalcul,NULL);

    printf("moyenne %d\n", moyenne);

    duree = ((finCalcul.tv_sec - debutCalcul.tv_sec) * 1000000) + (finCalcul.tv_usec - debutCalcul.tv_usec);
    printf( "Durée %ld ms\n", duree );

    return EXIT_SUCCESS;
}

int normaliseCapteur(int *valCapteur){
    int i = 0;
    int total=0;
    int moyenne;

    total = 0;
    while(valCapteur[i] != '\0'){
        total += valCapteur[i];
        i++;
    }
    moyenne = total / i;

    return(moyenne);
}

int *strip_extrema(int *array, int laps){
    for(int i=0 ; i<laps ; i++){
        int *maxi = find_max_addr(array);
        int j = 0;
        while(*(maxi+j) != '\0'){
            *(maxi+j) = *(maxi+j+1);
            j++;
        }
        int *mini = find_min_addr(array);
        j = 0;
        while(*(mini+j) != '\0'){
            *(mini+j) = *(mini+j+1);
            j++;
        }

    }
    return array;
}