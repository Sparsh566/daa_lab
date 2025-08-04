#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 100

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v], min_index = v;
        }
    }

    return min_index;
}

// Function to print the MST
void printTree(int parent[], int graph[V][V], int vertices) {
    printf("Edge -> Weight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d -> %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Prim's algorithm
void prim(int graph[V][V], int vertices) {
    int parent[vertices];   // Array to store constructed MST
    int key[vertices];      // Key values to pick min weight edge
    bool mstSet[vertices];  // To represent set of vertices in MST

    // Initialize all keys as infinite
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;        // Start from vertex 0
    parent[0] = -1;    // First node is always root

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;

        // Update key and parent of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printTree(parent, graph, vertices);
}

// Main function
int main() {
    int vertices;
    int graph[V][V];

    printf("No·of·vertices: ");
    scanf("%d", &vertices);

    printf("Adjacency·matrix·elements·(row·wise):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, vertices);

    return 0;
}
