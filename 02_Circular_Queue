#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Enqueue operation
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is Full\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    printf("%d inserted into queue\n", value);
}

// Dequeue operation
void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("%d deleted from queue\n", queue[front]);

    if (front == rear) {
        // Queue becomes empty
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display operation
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Circular Queue: ");

    int i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
