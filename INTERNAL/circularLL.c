#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *neww, *ptr, *ptr1, *header, *last;

int ch, item, pos, i;

void insertion();
void deletion();
void traverse();

void main() {
    header = NULL;
    while (1) {
        printf("**MENU**");
        printf("\n 1.Insertion\n 2.Deletion\n 3.Traverse\n 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insertion(); break;
            case 2: deletion(); break;
            case 3: traverse(); break;
            case 4: exit(0);
            default: printf("\nWRONG CHOICE!!!\n");
        }
    }
}
void insertion() {
    last = ptr = header;
    neww = malloc(sizeof(struct node));
    printf("\n Enter the item to be inserted: ");
    scanf("%d", &item);
    neww->data = item;
    if (header == NULL) {
        neww->link = neww;
        header = neww;
    } else {
        printf("\n Enter the place to insert: ");
        printf("\n 1.Start\n 2.Middle\n 3.End\n");
        scanf("%d", &ch);
        if (ch == 1) {
            while (last->link != header) {
                last = last->link;
            }
            neww->link = header;
            header = neww;
            last->link = header;
        }
        if (ch == 2) {
            printf("Enter the position to insert: ");
            scanf("%d", &pos);
            for (i = 1; i < pos - 1; i++) {
                ptr = ptr->link;
            }
            neww->link = ptr->link;
            ptr->link = neww;
        }
        if (ch == 3) {
            while (ptr->link != header) {
                ptr = ptr->link;
            }
            neww->link = header;
            ptr->link = neww;
        }
    }
}
void deletion() {
    ptr = last = header;
    if (header == NULL) {
        printf("\nThe list is EMPTY!!!\n");
    } else if (ptr->link == header) {
        printf("\n Deleted item is: %d", ptr->data);
        free(ptr);
        header = NULL;
    } else {
        printf("\n 1.Start\n 2.Middle\n 3.End\n");
        printf("\n Enter place to delete: ");
        scanf("%d", &ch);
        if (ch == 1) {
            while (last->link != header) last = last->link;
            printf("\n Deleted item is: %d", ptr->data);
            header = header->link;
            last->link = header;
            free(ptr);
        }
        if (ch == 2) {
            printf("\n Enter position to delete: ");
            scanf("%d", &pos);
            for (i = 1; i < pos; i++) {
                ptr1 = ptr;
                ptr = ptr->link;
            }
            printf("\n The deleted element is: %d", ptr->data);
            ptr1->link = ptr->link;
            free(ptr);
        }
        if (ch == 3) {
            while (ptr->link != header) {
                ptr1 = ptr;
                ptr = ptr->link;
            }
            printf("the deleted element is: %d", ptr->data);
            ptr1->link = header;
            free(ptr);
        }
    }
}
void traverse() {
    int i = 0;
    if (header == NULL)
        printf("List is EMPTY!!!");
    else {
        printf("\n The elements in the list are (Reversed): ");
        ptr = header;
        do {
            printf(" %d", ptr->data);
            ptr = ptr->link;
        } while (ptr != header);
    }
}