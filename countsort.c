#include <stdio.h>
#include <stdlib.h>
#include "array_read.h"

int MAX_LAENGE = 1000;
int MAX_VALUE = 100;

void count_sort_calculate_counts(int input_array[], int len, int count_array[]) {
    int i = 0;
    for (i=0; i < len; i++){
        count_array[input_array[i]] += 1;
    };
}

void count_sort_output_array(int output_array[], int len, int count_array[]) {
    int i, j, k = 0;

    for (i=0; i <= MAX_VALUE; i++){
        for (j=0; j < count_array[i]; j++){
            output_array[k] = i;
            k += 1;
        };
    };
}



int main(int argc, char *argv[]) {

    if (argc < 2){
        printf("Aufruf: %s <Dateiname>\n", argv[0]);
        printf("Beispiel: %s zahlen.txt\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    int input_array[MAX_LAENGE];
    int len = read_array_file(input_array, MAX_LAENGE, filename);

    printf("Unsortiertes Array:");
    print_array(input_array, len);

    int count_array[MAX_VALUE], i;
    int output_array[len];

    for (i=0; i< MAX_VALUE; i++){
        count_array[i] = 0;
    };

    count_sort_calculate_counts(input_array, len, count_array);
    count_sort_output_array(output_array, len, count_array);

    printf("Sortiertes Array:");

    /* Folgende Zeile einkommentieren, um das Array auszugeben! */
    print_array(output_array, len);

    return 0;
}
