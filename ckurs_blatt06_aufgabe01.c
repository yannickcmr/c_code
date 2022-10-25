#include <stdio.h>
#include <stdlib.h>
#include "input2.h"

int main(){
    // vorgegebene variablen.
    int n = lese_int();
    int laenge = n - 1;

    // programm variablen.
    int i, j, upper_border, *array_num;
    // speicherplatz reservieren.
    array_num = (int*) malloc(laenge * sizeof(int));
    if (array_num == NULL){
        perror("speicherplatzfeher");
        exit(1);
    };
    // definiere die werte in den arrays.
    for (i = 0; i < laenge; i++){
        array_num[i] = 1;
    };
    // berechnung der primzahlen.
    for (i = 0; i < laenge; i++){
        if (array_num[i] == 1){
            upper_border = ((laenge - (laenge%(i+2))) / (i+2)) + 1;
            for (j=1; j < upper_border; j++){
                if ((i + j*(i+2)) < laenge){
                    array_num[(i + j*(i+2))] = 0;   
                };  
            };
        };
    };
    // print und frei geben des speichers.
    print_prim(array_num, laenge);
    /*for (i=0; i<laenge; i++){
        if (array_num[i] == 1){
           printf("%d, ", i+2); 
        };  
    };*/
    free(array_num);
    return 0;
}