#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int info;
    struct Node* next;
};

// Function to create a new node
struct Node* getnode() {
    struct Node* newptr = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for the new node: ");
    scanf("%d", &(newptr->info));
    return newptr;
}

// Global pointers for the head and last nodes
struct Node* nodeptr = NULL;
struct Node* last = NULL;

// Function to create a circular linked list
void createList() {
    char choice;
    
    do {
        struct Node* newptr = getnode();
        
        
        if (nodeptr == NULL) {
            nodeptr = newptr;
        } else {
            last->next = newptr;
            newptr->next = nodeptr;
        }
        
        last = newptr;
        
        printf("Do you want to add more nodes? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

// Function to traverse the circular linked list
void traverseList() {
    if (nodeptr == NULL) {
        printf("Circular LinkedList is empty.\n");
        return;
    }

    struct Node* ptr = nodeptr;

    do {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    } while (ptr != nodeptr);

    printf("\n");
}

// Function to insert a node in the circular linked list
void insertNode(int key) {
    if (nodeptr == NULL) {
        printf("Circular LinkedList is empty. Cannot insert.\n");
        return;
    }

    struct Node* newptr = getnode();

    struct Node* ptr = nodeptr;

    do {
        ptr = ptr->next;
    } while (ptr->info != key && ptr != nodeptr);

    if (ptr->info != key) {
        printf("Node with key %d not found.\n", key);
    } else {
        newptr->next = ptr->next;
        ptr->next = newptr;
    }
}

// Function to delete a node from the circular linked list
void deleteNode(int key) {
    if (nodeptr == NULL) {
        printf("Circular LinkedList is empty. Cannot delete.\n");
        return;
    }

    struct Node *ptr = nodeptr, *prevptr;

    do {
        prevptr = ptr;
        ptr = ptr->next;
    } while (ptr->info != key && ptr != nodeptr);

    if (ptr->info != key) {
        printf("Node with key %d not found.\n", key);
    } else {
        prevptr->next = ptr->next;
        if(ptr == nodeptr)
            nodeptr = ptr->next;
        free(ptr);
    }
}

// Main function
int main() {
    int ch, x;
    printf("CIRCULAR LINKEDLIST IMPLEMENTATION.\n\n");
    createList();
    while(1) {
        printf("1. Insert.\n"
            "2. Remove.\n"
            "3. Print\n"
            "4. Exit\n"
            ">> ");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the key of node after which new node should be inserted: ");
            scanf("%d", &x);
            insertNode(x);
            break;
        case 2:
            printf("Enter the key of node which is to be removed: ");
            scanf("%d", &x);
            deleteNode(x);
            break;
        case 3:
            traverseList();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid option %d\n", ch);
            break;
        }
    } 

    return 0;
}
