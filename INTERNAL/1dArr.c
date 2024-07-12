#include <stdio.h>
#include <stdlib.h>
void create();
void insert();
void dele();
void search();
void traverse();
int list[20], i, n, pos, ele, ch, found, key;
int main() {
    do {
        printf("Enter your choice:\n");
        printf("1. Create\n2. Insert\n3. Delete\n4. Search\n5. Traverse\n6. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1: create(); break;
        case 2: insert(); break;
        case 3: dele(); break;
        case 4: search(); break;
        case 5: traverse(); break;
        case 6: exit(0); break;
        default: printf("Invalid choice, please enter a valid option.\n");
        }
    } while (ch < 7);
    return 0;
}
void create() {
    printf("Enter the number of elements (n):\n");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
}
void insert() {
    printf("Enter the element to be inserted:\n");
    scanf("%d", &ele);
    printf("Enter the position where it should be inserted (1 to %d):\n", n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return;
    }
    for (i = n - 1; i >= pos - 1; i--) {
        list[i + 1] = list[i];
    }
    list[pos - 1] = ele;
    n++;
}
void dele() {
    printf("Enter the position of the element to be deleted (1 to %d):\n", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return;
    }
    for (i = pos - 1; i < n - 1; i++) {
        list[i] = list[i + 1];
    }
    n--;
}
void search() {
    printf("Enter the key element to be searched:\n");
    scanf("%d", &key);
    found = 0;
    for (i = 0; i < n; i++) {
        if (list[i] == key) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Element found at position %d.\n", i + 1);
    } else {
        printf("Element not found.\n");
    }
}
void traverse() {
    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", list[i]);
    }
    printf("\n");
}