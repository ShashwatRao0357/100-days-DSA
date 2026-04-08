#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int adj[MAX][MAX];  
    int visited[MAX];   
    int stack[MAX];     
    int top;            
    int numVertices;    
} Graph;

void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    g->top = -1;
    
    for (int i = 0; i < vertices; i++) {
        g->visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int u, int v) {
    g->adj[u][v] = 1;
}

void dfsTopological(Graph *g, int vertex) {
    g->visited[vertex] = 1;
    
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adj[vertex][i] == 1 && !g->visited[i]) {
            dfsTopological(g, i);
        }
    }
    
    g->stack[++(g->top)] = vertex;
}

void topologicalSort(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        g->visited[i] = 0;
    }
    g->top = -1;
    
    for (int i = 0; i < g->numVertices; i++) {
        if (!g->visited[i]) {
            dfsTopological(g, i);
        }
    }
    
    printf("Topological Order: ");
    while (g->top >= 0) {
        printf("%d ", g->stack[g->top--]);
    }
    printf("\n");
}

void displayGraph(Graph *g) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    int vertices, edges, u, v;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    initGraph(&g, vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }
    
    displayGraph(&g);
    topologicalSort(&g);
    
    return 0;
}