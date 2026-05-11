#include <stdio.h>
#include <stdbool.h>

#define V 15
#define INF 99999

void printDijkstra(int dist[], int parinte[], int sursa, int dest, int graf[V][V]) {
    printf("Ordinea nodurilor (invers): %d", dest);
    int temp = dest;
    int muchii[V], k = 0;
    
    while (parinte[temp] != -1) {
        muchii[k++] = graf[parinte[temp]][temp];
        temp = parinte[temp];
        printf(" <- %d", temp);
    }
    
    printf("\nValorile muchiilor din drum: ");
    for (int i = 0; i < k; i++) printf("[%d] ", muchii[i]);
    
    printf("\nCost total: %d\n", dist[dest]);
}

void dijkstra(int graf[V][V], int sursa, int dest) {
    int dist[V], parinte[V];
    bool vizitat[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        vizitat[i] = false;
        parinte[i] = -1;
    }

    dist[sursa] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INF, u = -1;
        for (int v = 0; v < V; v++)
            if (!vizitat[v] && dist[v] <= min) { min = dist[v]; u = v; }

        if (u == -1) break;
        vizitat[u] = true;

        for (int v = 0; v < V; v++)
            if (!vizitat[v] && graf[u][v] != INF && dist[u] + graf[u][v] < dist[v]) {
                parinte[v] = u;
                dist[v] = dist[u] + graf[u][v];
            }
    }
    printDijkstra(dist, parinte, sursa, dest, graf);
}

int main() {
    int graf[V][V];
    for(int i=0; i<V; i++) for(int j=0; j<V; j++) graf[i][j] = (i==j?0:INF);
    
    // Adaugare 15+ muchii (Graful Nou)
    graf[0][1]=4; graf[0][2]=2; graf[1][3]=5; graf[2][3]=8; graf[3][4]=2;
    graf[4][5]=3; graf[5][6]=4; graf[6][7]=1; graf[7][8]=2; graf[8][9]=3;
    graf[9][10]=1; graf[10][11]=2; graf[11][12]=1; graf[12][13]=3; graf[13][14]=2;
    // Muchii cu cost negativ (pentru comparatie ulterior)
    graf[3][6]=-4; graf[6][10]=-2;

    dijkstra(graf, 0, 14);
    return 0;
}