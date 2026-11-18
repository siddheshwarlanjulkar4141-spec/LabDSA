#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Enqueue operation (your exact code)
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

// Dequeue operation (your exact code)
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

// Display operation (your exact code)
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

// Updated main function with user input
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please choose between 1 and 4.\n");
        }
    }

    return 0;
}
