#include <stdio.h>
#include <stdlib.h>

int main(){
int *ptr;
int n, i;

printf("Enter number of elements: ");
scanf("%d", &n);

ptr = (int *)malloc(n * sizeof(int));

if(ptr == NULL) {
  printf("Error! memory not allocated.");
} else {
  printf("Memory successfully allocated! using MALLOC");
  for (int i = 0; i < n; ++i) {
    ptr[i] = i + 1;
  }
  printf("The elements in the array are: ");
  for(i = 0; i < n; i++) {
    printf("%2d\n", ptr[i]);
  }
}
  return 0;
}

