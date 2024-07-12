#include<stdio.h>
#include<stdlib.h>

void insertion();
void deletion();
void traverse();

struct node {
    int data;
    struct node *next;
    struct node *prev;
} *new_node, *header, *ptr, *ptr1;

int i, pos, item, ch;

int main() {
    header = NULL;
    printf(" ***** MENU ****");
    printf("\n1.Insertion \n2.Deletion \n3.Traverse \n4.Exit\n");
    while (1) {
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong choice");
        } /* end of switch */
    } /* end of while */
    return 0;
} /* end of main */

void insertion() {
    ptr = header;
    new_node = malloc(sizeof(struct node));
    printf("\nEnter the item to be inserted: ");
    scanf("%d", &item);
    new_node->data = item;
    if (header == NULL) {
        new_node->prev = NULL;
        new_node->next = NULL;
        header = new_node;
    } else {
        printf("\nSelect the place:");
        printf("\n1.Start \n2.Middle \n3.End\n");
        scanf("%d", &ch);
        if (ch == 1) {
            new_node->next = ptr;
            new_node->prev = NULL;
            ptr->prev = new_node;
            header = new_node;
        } /* choice1 */

        if (ch == 3) {
            while (ptr->next != NULL)
                ptr = ptr->next;
            new_node->next = NULL;
            new_node->prev = ptr;
            ptr->next = new_node;
        } /* choice3 */
    } /* end of else */
} /* end of insertion */

void deletion() {
    ptr = header;
    if (header == NULL)
        printf("The list is empty\n");
    else if (ptr->next == NULL) {
        printf("Deleted item is:%d", ptr->data);
        free(ptr);
        header = NULL;
    } else {
        printf("\nSelect the place:");
        printf("\n1.Start \n2.Middle \n3.End\n");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("\nThe deleted item is: %d", ptr->data);
            ptr1 = ptr->next;
            header = ptr1;
            ptr1->prev = NULL;
            free(ptr);
        } /* choice1 */

        if (ch == 3) {
            while (ptr->next != NULL)
                ptr = ptr->next;
            printf("\nThe deleted node is: %d", ptr->data);
            ptr1 = ptr->prev;
            ptr1->next = NULL;
            free(ptr);
        } /* choice3 */
    }     /*end of else*/
} /*end of deletion */

void traverse() {
    ptr = header;
    if (header == NULL)
        printf("The list is empty\n");
    else {
        printf("\n\nThe elements in forward order: ");
        for (; ptr != NULL; ptr = ptr->next) {
            printf("  %d", ptr->data);
            ptr1 = ptr;
        }
        printf("\n\nThe elements in reverse order: ");
        for (; ptr1 != NULL; ptr1 = ptr1->prev)
            printf("  %d", ptr1->data);
    } /* end of else */
}
