#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int priority;
    char device[20];
    struct node *next;
};

struct node *head = NULL;

void insert_request() {
    struct node *newnode, *temp, *prev;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter device name (Keyboard, Mouse, Scanner, Printer): ");
    scanf("%s", newnode->device);
    if (strcmp(newnode->device, "Keyboard") == 0)
        newnode->priority = 1;
    else if (strcmp(newnode->device, "Mouse") == 0)
        newnode->priority = 2;
    else if (strcmp(newnode->device, "Scanner") == 0)
        newnode->priority = 3;
    else if (strcmp(newnode->device, "Printer") == 0)
        newnode->priority = 4;
    else {
        printf("Invalid device name.\n");
        free(newnode);
        return;
    }
    newnode->next = NULL;
    if (head == NULL || head->priority > newnode->priority) {
        newnode->next = head;
        head = newnode;
    } else {
        temp = head;
        while (temp != NULL && temp->priority <= newnode->priority) {
            prev = temp;
            temp = temp->next;
        }
        newnode->next = prev->next;
        prev->next = newnode;
    }
    printf("Inserted device: %s with priority: %d\n", newnode->device, newnode->priority);
}

void process_request() {
    struct node *temp;
    if (head == NULL) {
        printf("No requests to process. The queue is empty.\n");
        return;
    }
    temp = head;
    printf("Processing device: %s with priority: %d\n", temp->device, temp->priority);
    head = head->next;
    free(temp);
}

void display_requests() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("The priority queue is empty.\n");
        return;
    }
    printf("Current requests in the queue (Device - Priority):\n");
    while (temp != NULL) {
        printf("%s - %d\n", temp->device, temp->priority);
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Insert Request\n2. Process Request\n3. Display Requests\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_request();
                break;
            case 2:
                process_request();
                break;
            case 3:
                display_requests();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
