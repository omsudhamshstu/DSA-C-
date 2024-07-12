#include <stdio.h>
#include <stdlib.h>
void traverse();
void deletion();
void insertion();
void search();
int ch,pos,val,i;
struct node {
    int data;
    struct node *link;
} *header,*ptr,*ptr1,*new;
void main(){
    header = NULL;
    while(1){
        printf("***MENU***\n");
        printf("\n1.Insertion\n2.Deletion\n3.Traverse\n4.Search\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1 : insertion();
                break;
            case 2 : deletion();
                break;
            case 3 : traverse();
                break;
            case 4 : search();
                break;
            case 5 : exit(0);
            default:printf("\n WRONG CHOICE!\n");
        }
    }
}
void insertion(){
    ptr = header;
    new = malloc(sizeof(struct node));
    printf("Enter the val to be inserted: ");
    scanf("%d",&val);
    new->data = val;
    if(header == NULL){
        new->link = NULL;
        header = new;
    } else {
        printf("\nEnter the place to insert: ");
        printf("1.Start\n2.Middle\n3.End\n");
        scanf("%d",&ch);
        if(ch == 1){
            new -> link = header;
            header = new;
        }
        if(ch == 2){
            printf("Enter the position to place: ");
            scanf("%d",&pos);
            for(i=1; i<pos-1; ++i)
                ptr = ptr->link;
            new->link = ptr->link;
            ptr->link = new;
        }
        if(ch == 3){
            while(ptr->link != NULL)
                ptr = ptr->link;
            new->link = NULL;
            ptr->link = new;
        }
    }
}
void deletion(){
    ptr = header;
    if(header == NULL){
        printf("The list is EMPTY");
    } else if (ptr->link == NULL){
        printf("Declared val is -> %d",ptr->data);
        free(ptr);
        header = NULL;
    } else {
        printf("\n1.Starting \n2.Middle \n3.End \n");
        printf("Enter the place to delete: ");
        scanf("%d", &ch);
        if(ch == 1){
            printf("The deleted element is -> %d\n",ptr->data);
            header = header->link;
            free(ptr);
        }
        if(ch == 2){
            printf("Enter the element to remove: ");
            scanf("%d", &pos);
            for(i=1; i<pos; ++i){
                ptr1=ptr;
                ptr=ptr->link;
            }
            printf("The deleted element from the list is -> %d",ptr->data);
            ptr1->link=ptr->link;
            free(ptr);
        }
        if(ch == 3){
            while(ptr->link!=NULL){
                ptr1=ptr;
                ptr=ptr->link;
            }
            printf("\n The deleted element is -> %d",ptr->data);
            ptr1->link=NULL;
            free(ptr);
        }
    }
}
void search(){
    int loc=0,f=0;
    printf("Enter element to be searched: ");
    scanf("%d",&val);
    for(ptr=header; ptr!=NULL; ptr->link){
        loc++;
        if(ptr->data == val){
            f=1;
            break;
        }
    }
    if (f==0) {
        printf("\n Element not found!");
    } else {
        printf("The element was found at location %d",loc);
    }
}
void traverse(){
    if(header == NULL)
        printf("The list is EMPTY");
    else {
        printf("The elements in the list are: ");
        for(ptr=header; ptr!=NULL; ptr=ptr->link){
            printf(" %d",ptr->data);
        }
    }
}