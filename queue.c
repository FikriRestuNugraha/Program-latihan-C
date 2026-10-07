#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front =-1, rear = -1;

void enqueue(int value) {
	if (rear == SIZE -1) {
	 printf("Queue is full! Cannot enqueue %d.\n", value);
    } else {
        if (front == -1)
            front = 0;

        queue[++rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        printf("Dequeued: %d\n", queue[front++]);

        if (front > rear)
            front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");

        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();

    return 0;
}