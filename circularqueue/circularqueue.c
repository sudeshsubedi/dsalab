#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front, rear, size;
} CircularQueue;

CircularQueue* init_queue(int size) {
    CircularQueue *q = (CircularQueue*) malloc(sizeof(CircularQueue));
    q->data = (int*) malloc(sizeof(int)*size);
    q->size = size;
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(CircularQueue *q, int x) {
    if ( (q->rear + 1) % q->size == q->front) {
        printf("Error: Queue is full\n");
        return;
    }
    q->rear = (q->rear+1) % q->size;
    q->data[q->rear] = x;
}

void dequeue(CircularQueue *q) {
    if (q->rear == q->front) {
        printf("Error: Queue is empty.\n");
        return;
    }
    q->front = (q->front+1)%q->size;
    printf("Dequeued value: %d\n", q->data[q->front]);
}

void printqueue(CircularQueue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty");
        return;
    }
    for(int i=q->front+1; i<=q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    int n, ch, x;
    printf("CIRCULAR QUEUE IMPLEMENTATION.\n\n");
    printf("Enter the size of queue: ");
    scanf("%d", &n);
    CircularQueue *q = init_queue(n);
    while(1) {
        printf("1. Enqueue.\n"
            "2. Dequeue.\n"
            "3. Print\n"
            "4. Exit\n"
            ">> ");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data to enqueue: ");
            scanf("%d", &x);
            enqueue(q, x);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            printqueue(q);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid option %d\n", ch);
            break;
        }
    } 
}