#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.c"

// struct node
struct node{
    int vertex;
    struct node* next;
};
// struct Graph     
struct Graph{
    int numVertex;             // total vertices
    struct node** adjList;     // list of pointers to nodes
    int* visited;
    // for shortest path or layers
    int* dist;
};  

// create node  ie our vertex
struct node* createNode(int v){
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// create graph  to be intialized just once obvio
struct Graph* createGraph(int vertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph*));
    graph->numVertex = vertices;

    //initialize adjlist and point each to null
    graph->adjList = (struct node**)malloc(vertices * sizeof(struct node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));       // debugged: mem allocation dont forget!!
    graph->dist    = (int*)malloc(vertices * sizeof(int));       

    for(int i=0;i<vertices;i++){
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
        if(i==0){
        graph->dist[i] = 0;     // dist of start vertex is 0
        }
        else{
        graph->dist[i] = 9999;  // prefereably initialize to +infinty

        }
    }
    return graph;
}


// add edge

void addEdge(struct Graph* graph,int s ,int d){
    // from vertex s to d
    struct node* newNode = createNode(d);
    newNode->next = graph->adjList[s];
    graph->adjList[s] = newNode;

    // from d to s
    newNode = createNode(s);
    newNode->next = graph->adjList[d];
    graph->adjList[d] = newNode;
}

// print graph

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertex; v++) {
    struct node* temp = graph->adjList[v];
    printf("\n Vertex %d, Layer = %d\n: ", v,graph->dist[v]);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}



// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);
  // (v,w)
  while (!isEmpty(q)) {
    printQueue(q);
    int v = dequeue(q);
    printf("Visited %d\n", v);

    struct node* temp = graph->adjList[v];

    while (temp) {
      int w = temp->vertex;

      if (graph->visited[w] == 0) {
        graph->visited[w] = 1;
        graph->dist[w]  = graph->dist[v]+1;  
        enqueue(q, w);
      }
      temp = temp->next;
    }
  }
}

int main() {
struct Graph* graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 3, 5);
  addEdge(graph, 4, 5);
  bfs(graph,0);
  printGraph(graph);

  return 0;
}
