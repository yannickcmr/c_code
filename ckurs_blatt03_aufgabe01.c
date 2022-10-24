#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variablen.
    int hoehe = 3;
    int breite = 4;

    // create templates.
    char top_row[breite + 2];
    char mid_row[breite + 2]; 
    int i;

    top_row[0] = 'A';
    mid_row[0] = 'A';

    if (breite > 0){
        for (i = 1; i < breite + 1; i++) {
            top_row[i] = 'A';
            mid_row[i] = 'B';
        };
    };
    top_row[breite + 1] = 'A';
    mid_row[breite + 1] = 'A';

    // put templates in order.
    printf("%s\n", top_row);
    if (hoehe > 0) {
        for (i = 0; i < hoehe; i++){
            printf("%s\n", mid_row);
        };
    };
    printf("%s\n", top_row);
    return 0;
}
