#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 40

struct queue {
  int items[SIZE];
  int front;
  int rear;
};

/* struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q); */
// Create a queue
struct queue* createQueue() {
  struct queue* q = (struct queue*)malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
bool isEmpty(struct queue* q) {
  if (q->rear == -1)
    return true;
  else
    return false;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
      q->rear++;
      q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;                    // dequeued item
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->items[i]);
    }
  }
  printf("\n");
}

void main(){
    struct queue* Q = createQueue();
    enqueue(Q,1);
    enqueue(Q,2);
    enqueue(Q,4);
    dequeue(Q);
    printQueue(Q);

}