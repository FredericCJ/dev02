#include <stdio.h>
#include <sys/time.h>

int normaliseCapteur( int valCapteur[8] );
int min(int *);
int max(int *);
int moyenne(int *);

int main(void)
{
    int valCapteur[8] = { 2, 56, 180, 60, 10, 1020, 65, 55 };
    //int valCapteur[4] = {56, 60, 65, 55};
    int moyenne;

    int j;
    unsigned long duree;
    struct timeval debutCalcul, finCalcul;
    gettimeofday(&debutCalcul,NULL);
    for( j = 0; j < 10000; j++) {
        moyenne = normaliseCapteur(valCapteur);
    }
    gettimeofday(&finCalcul,NULL);
    printf("moyenne %d\n", moyenne);
    duree = ((finCalcul.tv_sec - debutCalcul.tv_sec) * 1000000) + (finCalcul.tv_usec - debutCalcul.tv_usec);
    printf( "Durée %ld ms\n", duree );
}

int normaliseCapteur( int valCapteur[8] )
{
    int i;
    int total=0;
    int moyenne;

    total = 0;
    for( i = 0; i < 8; i++) {
        total += valCapteur[i];
    }
    moyenne = total / 8;

    return(moyenne);
}

int min(int *valCapteur){
    int i = 0;
    float max = 1024;
    while(*(valCapteur+i) != '\0'){
        if(*(valCapteur+i) <= max){
            max = *(valCapteur+i);
        }
        i++;
    }
    return max;
}

int max(int *valCapteur){
    int i = 0;
    float min = 0;
    while(*(valCapteur+i) != '\0'){
        if(*(valCapteur+i) >= min){
            min = *(valCapteur+i);
        }
        i++;
    }
    return min;
}

int moyenne(int *valCapteur){
    int i = 0;
    int moyenne = 0;
    while(*(valCapteur+i) != '\0'){
        moyenne = *(valCapteur+i)+moyenne;
        i++;
    }
    moyenne = moyenne/i;
    return moyenne;
}