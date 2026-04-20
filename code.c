#include <stdio.h>
#include <string.h>

#define MAX 5  

char queue[MAX][50]; 
int front = -1;
int rear = -1;


void enqueue(char name[]) {
    if ((rear + 1) % MAX == front) {
        printf("\n Queue is Full! Cannot add more bookings.\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        strcpy(queue[rear], name);
        printf(" %s joined the queue at position %d.\n", name, rear + 1);
    }
}

void dequeue() {
    if (front == -1) {
        printf("\n Queue is Empty! No tickets to book.\n");
    } else {
        printf("\n Ticket Successfully Booked for: %s\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}


void display() {
    if (front == -1) {
        printf("\n Status: Queue is empty.\n");
    } else {
        printf("\n Current Waiting List \n");
        int i = front;
        while (1) {
            printf("-> %s\n", queue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char name[50];

    while (1) {
        printf("\n Railway Ticket Counter System ");
        printf("\n1. Join Queue (Enqueue)");
        printf("\n2. Book Ticket (Dequeue)");
        printf("\n3. View Waiting List");
        printf("\n4. Exit");
        printf("\nSelect an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                enqueue(name);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
