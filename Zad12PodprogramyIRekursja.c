#include <stdio.h>
#include <string.h>

#define MAX_TOWARY 50

typedef struct {
    char nazwaTowaru[100];
    int liczbaSztuk;
    float cena1Sztuki;
} Towar;

void dodajTowar(Towar tablicaTowarow[], int *liczbaTowarow) {
    if (*liczbaTowarow >= MAX_TOWARY) {
        printf("Rejestr jest pełny.\n");
        return;
    }
    
    Towar nowyTowar;
    printf("Podaj nazwę towaru: ");
    scanf("%s", nowyTowar.nazwaTowaru);
    printf("Podaj liczbę sztuk: ");
    scanf("%d", &nowyTowar.liczbaSztuk);
    printf("Podaj cenę za sztukę: ");
    scanf("%f", &nowyTowar.cena1Sztuki);

    tablicaTowarow[*liczbaTowarow] = nowyTowar;
    (*liczbaTowarow)++;
}

void wyswietlTowary(Towar tablicaTowarow[], int liczbaTowarow) {
    if (liczbaTowarow == 0) {
        printf("Rejestr jest pusty.\n");
        return;
    }

    for (int i = 0; i < liczbaTowarow; i++) {
        printf("Towar %d: %s, Liczba sztuk: %d, Cena za sztukę: %.2f\n", 
               i + 1, tablicaTowarow[i].nazwaTowaru, tablicaTowarow[i].liczbaSztuk, tablicaTowarow[i].cena1Sztuki);
    }
}

void obliczSumeWartosci(Towar tablicaTowarow[], int liczbaTowarow) {
    float suma = 0;
    for (int i = 0; i < liczbaTowarow; i++) {
        suma += tablicaTowarow[i].liczbaSztuk * tablicaTowarow[i].cena1Sztuki;
    }
    printf("Suma wartości wszystkich towarów: %.2f\n", suma);
}

int main() {
    Towar tablicaTowarow[MAX_TOWARY];
    int liczbaTowarow = 0;
    char opcja;

    do {
        printf("Wybierz opcję:\n");
        printf("N | n – nowy towar\n");
        printf("W | w – wyświetl wszystkie towary\n");
        printf("R | r – oblicz sumę wartości wszystkich towarów\n");
        printf("Q | q – koniec programu\n");
        scanf(" %c", &opcja);

        switch(opcja) {
            case 'N':
            case 'n':
                dodajTowar(tablicaTowarow, &liczbaTowarow);
                break;
            case 'W':
            case 'w':
                wyswietlTowary(tablicaTowarow, liczbaTowarow);
                break;
            case 'R':
            case 'r':
                obliczSumeWartosci(tablicaTowarow, liczbaTowarow);
                break;
            case 'Q':
            case 'q':
                printf("Koniec programu.\n");
                break;
            default:
                printf("Nieznana opcja.\n");
                break;
        }
    } while (opcja != 'Q' && opcja != 'q');

    return 0;
}
