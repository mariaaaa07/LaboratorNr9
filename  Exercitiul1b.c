#include <stdio.h>

#define V 15
#define E 17
#define INF 99999

struct Muchie { int u, v, w; };

void bellmanFord(struct Muchie muchii[], int sursa, int dest) {
    int dist[V], parinte[V];
    for (int i = 0; i < V; i++) { dist[i] = INF; parinte[i] = -1; }
    dist[sursa] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[muchii[j].u] != INF && dist[muchii[j].u] + muchii[j].w < dist[muchii[j].v]) {
                dist[muchii[j].v] = dist[muchii[j].u] + muchii[j].w;
                parinte[muchii[j].v] = muchii[j].u;
            }
        }
    }

    // Afisare Rezultate
    printf("Ordinea nodurilor: ");
    int cale[V], index = 0, temp = dest;
    while(temp != -1) { cale[index++] = temp; temp = parinte[temp]; }
    for(int i = index-1; i >= 0; i--) printf("%d ", cale[i]);

    printf("\nCost total Bellman-Ford: %d\n", dist[dest]);
}

int main() {
    struct Muchie muchii[E] = {
        {0,1,4}, {0,2,2}, {1,3,5}, {2,3,8}, {3,4,2}, {4,5,3}, 
        {5,6,4}, {6,7,1}, {7,8,2}, {8,9,3}, {9,10,1}, {10,11,2}, 
        {11,12,1}, {12,13,3}, {13,14,2}, {3,6,-4}, {6,10,-2}
    };

    bellmanFord(muchii, 0, 14);
    return 0;
}