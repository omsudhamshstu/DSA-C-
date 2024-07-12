// #include <stdio.h>
// #include <stdlib.h>

// struct node {
// int val;
// struct node *next;
// }*head;

// void delete_at_beginning() {
//     if (head == NULL) {
//         printf("List is empty\n");
//         return;
//     }
//     struct node *temp = head;
//     head = head->next;
//     free(temp);
// }
// //-------------------------------------------------//

// void delete_at_end() {
//     if (head == NULL) {
//         printf("List is empty\n");
//         return;
//     }
//     struct node *temp = head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     free(temp->next);
//     temp->next = NULL; //second to last node's next pointer is set to NULL
// }

// //-------------------------------------------------//

// void delete_at_position(int pos) {
//     if (head == NULL){
//         printf("List is empty\n");
//     }
//     struct node *temp = head;
//     for (int i = 0; i < pos - 1 && temp != NULL){
//         temp = temp->next;
//     }
//     if (temp == NULL) 
// }
