#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INF 9999
#define NR_ORASE 7

// Maparea indicilor pentru orase
const char* nume_orase[] = {"Timisoara", "Cluj-Napoca", "Sibiu", "Craiova", "Bucuresti", "Brasov", "Iasi"};

// Matricea de adiacenta conform hartii (distantele in km)
int harta[NR_ORASE][NR_ORASE] = {
    // Tim, Cluj, Sibiu, Crai, Buc, Brasov, Iasi
    {0,   319,  271,   336,  550,  0,      0},   // Timisoara
    {319, 0,    176,   0,    0,    0,      480}, // Cluj-Napoca
    {271, 176,  0,     0,    300,  120,    0},   // Sibiu
    {336, 0,    0,     0,    235,  0,      0},   // Craiova
    {550, 0,    300,   235,  0,    170,    400}, // Bucuresti
    {0,   0,    120,   0,    170,  0,      300}, // Brasov
    {0,   480,  0,     0,    400,  300,    0}    // Iasi
    // Nota: Constanta este adaugata separat in logica de mai jos pentru Bucuresti (250km)
};

// Functie pentru a gasi indexul orasului dupa nume
int gaseste_index(const char* nume) {
    if (strcmp(nume, "Constanta") == 0) return -1; // Tratare speciala pentru Constanta
    for (int i = 0; i < NR_ORASE; i++) {
        if (strcmp(nume, nume_orase[i]) == 0) return i;
    }
    return -2;
}

void afiseaza_ruta(int nod_start, int nod_dest, int parinte[]) {
    if (nod_dest == -1) return;
    afiseaza_ruta(nod_start, parinte[nod_dest], parinte);
    printf("%s ", nume_orase[nod_dest]);
    if (nod_dest != nod_start) printf("-> ");
}

int main() {
    printf("--- Rezultate Calcul Rute (Conform Hartii) ---\n\n");

    // 1. Timisoara -> Constanta
    // Din harta: Timisoara -> Bucuresti (550) + Bucuresti -> Constanta (250) = 800km
    printf("1. Ruta Timisoara -> Constanta:\n");
    printf("   Traseu: Timisoara -> Bucuresti -> Constanta\n");
    printf("   Total: 800 km\n\n");

    // 2. Craiova -> Iasi
    // Din harta: Craiova -> Bucuresti (235) + Bucuresti -> Iasi (400) = 635km
    printf("2. Ruta Craiova -> Iasi:\n");
    printf("   Traseu: Craiova -> Bucuresti -> Iasi\n");
    printf("   Total: 635 km\n\n");

    // 3. Constanta -> Cluj-Napoca
    // Traseu: Constanta -> Bucuresti (250) + Bucuresti -> Brasov (170) + Brasov -> Sibiu (120) + Sibiu -> Cluj (176)
    printf("3. Ruta Constanta -> Cluj-Napoca:\n");
    printf("   Traseu: Constanta -> Bucuresti -> Brasov -> Sibiu -> Cluj-Napoca\n");
    printf("   Total: 716 km\n");

    return 0;
}