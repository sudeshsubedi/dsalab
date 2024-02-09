#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* lcptr;
    struct Node* rcptr;
};

struct Node* getnode(int key) {
    struct Node* newptr = (struct Node*)malloc(sizeof(struct Node));
    newptr->info = key;
    newptr->lcptr = NULL;
    newptr->rcptr = NULL;
    return newptr;
}

struct Node* insertNode(struct Node* root, int key) {
    struct Node *ptr = root, *parent = NULL, *newptr = getnode(key);

    while (ptr != NULL) {
        parent = ptr;
        if (newptr->info < ptr->info)
            ptr = ptr->lcptr;
        else
            ptr = ptr->rcptr;
    }

    if (parent == NULL)
        root = newptr;
    else if (newptr->info < parent->info)
        parent->lcptr = newptr;
    else
        parent->rcptr = newptr;

    return root;
}

int Insucc(struct Node* root) {
    while (root->lcptr != NULL)
        root = root->lcptr;
    return root->info;
}

struct Node* deleteNode(struct Node* root, int key) {
    struct Node *ptr = root, *parent = NULL;

    while (ptr != NULL && ptr->info != key) {
        parent = ptr;
        if (key < ptr->info)
            ptr = ptr->lcptr;
        else
            ptr = ptr->rcptr;
    }

    if (ptr == NULL)
        printf("Node with key %d doesn't exist.\n", key);
    else if (ptr->lcptr == NULL && ptr->rcptr == NULL) {
        if (key < parent->info)
            parent->lcptr = NULL;
        else
            parent->rcptr = NULL;
        free(ptr);
    } else if (ptr->lcptr == NULL || ptr->rcptr == NULL) {
        struct Node* child = (ptr->lcptr != NULL) ? ptr->lcptr : ptr->rcptr;
        if (key < parent->info)
            parent->lcptr = child;
        else
            parent->rcptr = child;
        free(ptr);
    } else {
        int del_data = Insucc(ptr->rcptr);
        root = deleteNode(root, del_data);
        ptr->info = del_data;
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->lcptr);
        printf("%d ", root->info);
        inorderTraversal(root->rcptr);
    }
}

int main() {
    struct Node* root = NULL;
    int ch, key;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Inorder Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insertNode(root, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}
