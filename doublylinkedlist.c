#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *Llink;
    struct node *Rlink;
};

struct node *head = NULL;

// Insert at beginning
void insertFirst() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNo space available\n");
        return;
    }
    printf("\nEnter the element to insert: ");
    scanf("%d", &newnode->data);
    newnode->Llink = NULL;
    newnode->Rlink = head;

    if (head != NULL)
        head->Llink = newnode;

    head = newnode;
    printf("%d inserted successfully\n", newnode->data);
}

// Insert at end
void insertLast() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nError: No space available\n");
        return;
    }
    printf("\nEnter the element to insert: ");
    scanf("%d", &newnode->data);
    newnode->Llink = NULL;
    newnode->Rlink = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->Rlink != NULL)
            temp = temp->Rlink;
        temp->Rlink = newnode;
        newnode->Llink = temp;
    }
    printf("%d inserted successfully\n", newnode->data);
}

// Insert after a specific element
void insertLocation() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    int key;
    printf("\nEnter the key after which to insert: ");
    scanf("%d", &key);

    struct node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->Rlink;

    if (temp == NULL) {
        printf("\nNo element found with key %d\n", key);
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nError: No space available\n");
        return;
    }

    printf("\nEnter the element to insert: ");
    scanf("%d", &newnode->data);

    newnode->Rlink = temp->Rlink;
    newnode->Llink = temp;
    if (temp->Rlink != NULL)
        temp->Rlink->Llink = newnode;
    temp->Rlink = newnode;

    printf("%d inserted successfully\n", newnode->data);
}

// Delete first node
void deleteFirst() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node *temp = head;
    printf("%d is deleted\n", temp->data);
    head = head->Rlink;

    if (head != NULL)
        head->Llink = NULL;

    free(temp);
}

// Delete last node
void deleteLast() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node *temp = head;

    if (temp->Rlink == NULL) {
        printf("%d is deleted\n", temp->data);
        head = NULL;
        free(temp);
        return;
    }

    while (temp->Rlink != NULL)
        temp = temp->Rlink;

    printf("%d is deleted\n", temp->data);
    temp->Llink->Rlink = NULL;
    free(temp);
}

// Delete by key
void deleteLocation() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    int key;
    printf("\nEnter the key to delete: ");
    scanf("%d", &key);

    struct node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->Rlink;

    if (temp == NULL) {
        printf("\nNo element found with key %d\n", key);
        return;
    }

    if (temp->Llink != NULL)
        temp->Llink->Rlink = temp->Rlink;
    else
        head = temp->Rlink;

    if (temp->Rlink != NULL)
        temp->Rlink->Llink = temp->Llink;

    printf("%d deleted successfully\n", temp->data);
    free(temp);
}

// Search for an element
void search() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    int key, pos = 0, found = 0;
    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->Rlink;
        pos++;
    }

    if (!found)
        printf("\nElement not found\n");
}

// Display all elements
void display() {
    if (head == NULL) {
        printf("\nNo elements in the list\n");
        return;
    }

    struct node *temp = head;
    printf("\n** Elements in the list **\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->Rlink;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice;
    do {
        printf("\n***** DOUBLY LINKED LIST *****\n");
        printf("1 -> Insert First\n");
        printf("2 -> Insert Last\n");
        printf("3 -> Insert After Location\n");
        printf("4 -> Delete First\n");
        printf("5 -> Delete Last\n");
        printf("6 -> Delete by Key\n");
        printf("7 -> Search\n");
        printf("8 -> Display\n");
        printf("9 -> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertFirst(); break;
            case 2: insertLast(); break;
            case 3: insertLocation(); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: deleteLocation(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: printf("\nExiting...\n"); exit(0);
            default: printf("\nEnter a valid choice\n");
        }
    } while (choice != 9);

    return 0;
}

