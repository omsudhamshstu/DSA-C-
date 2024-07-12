// #include <stdio.h>
// #include <stdlib.h>

// // creation of a node
// struct node {
//   int val;
//   struct node *next;
// } * head, *new_node, *temp;

// // code part for insertion(beg) in sll
// if (head == NULL) {
//   head = new_node;
//   new_node->next = NULL;
// } else {
//   new_node->next = head;
//   head = new_node;
// }

// // code part for insertion(end) in sll
// if (head == NULL) {
//   head = new_node;
// } else {
//   struct Node *temp = head;
//   while (temp->next != NULL) {
//     temp = temp->next;
//   }
//   temp->next = new_node;
// }
// // code part for insertion(pos) in sll
// new_node = (struct Node *)malloc(sizeof(struct Node));
// new_node->data = val;
// struct Node *temp = head;
// for (int i = 0; i < pos - 1 && temp != NULL; i++) {
//   temp = temp->next;
// }
// if (temp == NULL) {
//   printf("Position out of range.\n");
//   return; // or handle the error accordingly
// }
// if (temp == head) {
//   new_node->next = head;
//   head = new_node;
// } else {
//   new_node->next = temp->next;
//   temp->next = new_node;
// }

