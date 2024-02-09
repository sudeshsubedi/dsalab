#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* next;
    struct Node* prev;
};

struct Node* getnode() {
    struct Node* newptr = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for the new node: ");
    scanf("%d", &(newptr->info));
    newptr->next = NULL;
    newptr->prev = NULL;
    return newptr;
}

struct Node* head = NULL;

void createList() {
    char choice;
    struct Node* last = NULL;
    
    do {
        struct Node* newptr = getnode();
        
        if (head == NULL) {
            head = newptr;
        } else {
            last->next = newptr;
            newptr->prev = last;
        }
        
        last = newptr;
        
        printf("Do you want to add more nodes? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void traverseList() {
    if (head == NULL) {
        printf("Doubly LinkedList is empty.\n");
        return;
    }

    struct Node* ptr = head;

    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }

    printf("\n");
}

void insertNode(int key) {
    if (head == NULL) {
        printf("Doubly LinkedList is empty. Cannot insert.\n");
        return;
    }

    struct Node* newptr = getnode();
    struct Node* ptr = head;

    while (ptr != NULL && ptr->info != key) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Key not found.\n");
    } else {
        newptr->next = ptr->next;
        if (ptr->next != NULL) {
            (ptr->next)->prev = newptr;
        }
        ptr->next = newptr;
        newptr->prev = ptr;
    }
}

void deleteNode(int key) {
    if (head == NULL) {
        printf("Doubly LinkedList is empty.\n");
        return;
    }

    struct Node* ptr = head;

    while (ptr != NULL && ptr->info != key) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with key %d doesn't exist.\n", key);
    } else {
        if (ptr->prev != NULL) {
            (ptr->prev)->next = ptr->next;
        }
        if (ptr->next != NULL) {
            (ptr->next)->prev = ptr->prev;
        }
        if (ptr == head) {
            head = head->next;
        }
        free(ptr);
    }
}

int main() {
    int ch, x;
    printf("DOUBLY LINKEDLIST IMPLEMENTATION.\n\n");
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
