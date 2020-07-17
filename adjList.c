#include <stdio.h>
#include <stdlib.h>

// struct node
struct node{
    int vertex;
    struct node* next;
};
// struct Graph     
struct Graph{
    int numVertex;             // total vertices
    struct node** adjList;     // list of pointers to nodes
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

    //initialize adjlists and point each to null
    graph->adjList = (struct node**)malloc(vertices * sizeof(struct node*));

    for(int i=0;i<vertices;i++){
        graph->adjList[i] = NULL;
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
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 2);

  printGraph(graph);

  return 0;
}
