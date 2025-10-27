#include <stdio.h>
 
 
#define V 4
 
 
int main() {
    int adj[V][V] = {0}; 
 
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
 
 
    printf("Adjacency Matrix (Undirected Graph):\n");
    printf("    A B C D\n");
    for (int i = 0; i < V; i++) {
        printf("%c | ", 'A' + i);
        for (int j = 0; j < V; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
 
 
    return 0;
}
 
Is best to use an Adjecency Matrix when there are many edges to compare edges with multiple vertices.





#include <stdio.h>
#include <stdlib.h>
 
#define V 4
 
 
typedef struct Node {
  int vertex;
  struct Node* next;
} Node;
 
 
Node* createNode(int v) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}
 
void addEdge(Node* adjList[], int src, int dest) {
  Node* newNode = createNode(dest);
  newNode->next = adjList[src];
  adjList[src] = newNode;
}
 
void printGraph(Node* adjList[]) {
  printf("Adjacency List (Directed Graph):\n");
  for (int i = 0; i < V; i++) {
    printf("%c -> ", 'A' + i);
    Node* temp = adjList[i];
    while (temp) {
      printf("%c ", 'A' + temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}
 
int main() {
  Node* adjList[V] = {NULL};
 
  // edges: (A,B), (A,C), (B,D)
  addEdge(adjList, 0, 1);
  addEdge(adjList, 0, 2);
  addEdge(adjList, 1, 3);
 
  printGraph(adjList);
 
  return 0;
}
Is best to use an Adjecency List when there are few edges to save memory.
