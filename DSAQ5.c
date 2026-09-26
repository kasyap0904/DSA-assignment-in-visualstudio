#include <stdio.h>
#include <stdlib.h>

struct Node {
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

void display() {
    struct Node *p = head;
    printf("List: ");
    while (p != NULL) {
        printf("%d ", p->roll);
        p = p->next;
    }
    printf("\n");
}

void insertBeg(int roll) {
    struct Node *n = malloc(sizeof(struct Node));
    n->roll = roll;
    n->next = head;
    head = n;
    printf("After insertion at beginning:\n");
    display();
}

void insertEnd(int roll) {
    struct Node *n = malloc(sizeof(struct Node));
    n->roll = roll;
    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        struct Node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = n;
    }

    printf("After insertion at end:\n");
    display();
}

void search(int roll) {
    struct Node *p = head;

    while (p != NULL) {
        if (p->roll == roll) {
            printf("Roll number %d found\n", roll);
            return;
        }
        p = p->next;
    }

    printf("Roll number %d not found\n", roll);
}

void deleteNode(int roll) {
    struct Node *p = head, *prev = NULL;

    while (p != NULL && p->roll != roll) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("Roll number %d not found\n", roll);
        return;
    }

    if (prev == NULL)
        head = p->next;
    else
        prev->next = p->next;

    free(p);
    printf("After deletion:\n");
    display();
}

int main() {
    int choice, roll;

    while (1) {
        printf("\n1.Insert Beginning");
        printf("\n2.Insert End");
        printf("\n3.Search");
        printf("\n4.Delete");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertBeg(roll);
                break;

            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertEnd(roll);
                break;

            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                search(roll);
                break;

            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteNode(roll);
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}