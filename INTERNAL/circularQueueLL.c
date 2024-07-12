#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
}*front,*rear,*neww,*ptr,*ptr1;

void enqueue();
void dequeue();
void display();

int choice,i,item;

int main() {
    front=rear=NULL;
    printf("\n Select menu\n");
    while(1) {
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: enqueue();break;
            case 2: dequeue();break;
            case 3: display();break;
            case 4: exit(0);
            default: printf("\nWrong choice!");
        }
    }
}

void enqueue() {
    neww=malloc(sizeof(struct node));
    printf("\nEnter the item: ");
    scanf("%d",&item);
    neww->data=item;
    if(front==NULL)
        front=neww;
    else
        rear->link=neww;
    rear=neww;
    rear->link=front;
}

void dequeue(){
    if(front==NULL)
        printf("\nThe list is EMPTY!");
    else {
        ptr=front;
        printf("\nThe deleted element is: %d", ptr->data);
        if(front==rear) //List has single element
            front=rear=NULL;
        else
            front=front->link;
        free(ptr);
    }
    rear->link=front;
}

void display(){
    if(front==NULL)
        printf("\nThe circular list is EMPTY!.");
    else {
        printf("\nElements in the list are: ");
        ptr=front;
        do{
            printf(" %d",ptr->data);
            ptr=ptr->link;
        }while(ptr!=front);
    }
}