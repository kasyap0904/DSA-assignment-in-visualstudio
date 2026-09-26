#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char page[50];
    struct Node *prev, *next;
};

struct Node *head = NULL, *current = NULL;

void insert(char page[]) {
    struct Node *n = malloc(sizeof(struct Node));
    strcpy(n->page, page);
    n->prev = n->next = NULL;

    if (head == NULL) {
        head = current = n;
    } else {
        struct Node *p = head;
        while (p->next != NULL)
            p = p->next;

        p->next = n;
        n->prev = p;
    }

    printf("Page inserted: %s\n", page);
}

void forward() {
    if (current == NULL) {
        printf("No pages available\n");
        return;
    }

    if (current->next != NULL) {
        current = current->next;
        printf("Current page: %s\n", current->page);
    } else
        printf("Already at the last page\n");
}

void backward() {
    if (current == NULL) {
        printf("No pages available\n");
        return;
    }

    if (current->prev != NULL) {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    } else
        printf("Already at the first page\n");
}

void deletePage(char page[]) {
    struct Node *p = head;

    while (p != NULL && strcmp(p->page, page) != 0)
        p = p->next;

    if (p == NULL) {
        printf("Page not found\n");
        return;
    }

    if (p->prev != NULL)
        p->prev->next = p->next;
    else
        head = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;

    if (current == p)
        current = (p->next != NULL) ? p->next : p->prev;

    free(p);
    printf("Page deleted\n");
}

void display() {
    struct Node *p = head, *last = NULL;

    printf("First to Last: ");
    while (p != NULL) {
        printf("%s ", p->page);
        last = p;
        p = p->next;
    }

    printf("\nLast to First: ");
    while (last != NULL) {
        printf("%s ", last->page);
        last = last->prev;
    }
    printf("\n");
}

int main() {
    int choice;
    char page[50];

    while (1) {
        printf("\n1.Insert Page");
        printf("\n2.Move Forward");
        printf("\n3.Move Backward");
        printf("\n4.Delete Page");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter page name: ");
                scanf("%s", page);
                insert(page);
                break;

            case 2:
                forward();
                break;

            case 3:
                backward();
                break;

            case 4:
                printf("Enter page to delete: ");
                scanf("%s", page);
                deletePage(page);
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