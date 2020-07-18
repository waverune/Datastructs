#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// struct node
struct node{
    bool xplrd;
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
    newNode->xplrd = false;
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




//bfs
void bfs(struct Graph* graph,struct node* s){  // s is start vertex
    // mark s as explored
    s->xplrd = true;
    
    // intitialize queue Q with S
    enqueue(s);
    // while Q isnt empty
    while(isEmpty()){
        //remove first node of Q, call it v
        //for each (v,w)
        struct node* temp = graph->adjList[s->vertex];  // initial 0
          while(temp){
            temp = temp->next;  // becomes w
            //if w is unexplrd
            //mark w as xplrd and add it to Q
            if(temp->xplrd == false){
              temp->xplrd = true;
              enqueue(temp);
            }
          }
    }

}

int main() {
/*   struct Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 3, 5);
  addEdge(graph, 4, 5);
 */
  //printGraph(graph);
  printf("%s",!true);
  return 0;
}
