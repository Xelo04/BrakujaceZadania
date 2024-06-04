#include <stdio.h>

int main() {
    FILE *plik;
    int liczby[200][200];
    int suma[200];
    float srednia[200];
    
    int wiersz = 0;
    int kolumna=0;

    
    plik = fopen("plik.txt", "r");

    while (!feof(plik) && fscanf(plik, "%d", &liczby[wiersz][kolumna]) == 1) {
        suma[kolumna] += liczby[wiersz][kolumna];
        kolumna++;
        if (fgetc(plik) == '\n') { 
            wiersz++;
            kolumna = 0;
        }
    }

    
    for (int j=0; j<kolumna; j++) {
        srednia[j]=(float)suma[j]/kolumna;
    }

    for (int j = 0; j < kolumna; j++) {
        fprint(" %d", suma[j]);
    }

    for (int j = 0; j < kolumna; j++) {
        fprint(" %f", srednia[j]);
    }

}
