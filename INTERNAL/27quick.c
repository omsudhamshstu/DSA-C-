#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int subArr(int arr[], int low, int high){
  int pivot = arr[low];
  int i = low + 1;
  int j = high;
  
while (1) {
while (arr[i] <= pivot) {
  i++;
}
while (arr[j] > pivot) {
  j--;
}
if (i >= j) {
  break;
}
  swap(&arr[i], &arr[j]);
}
  swap(&arr[low], &arr[j]);
  return j;
}

void quick_s(int arr[], int low, int high){
  if(low < high) {
    int pivot = subArr(arr, low, high);
    quick_s(arr, low, pivot - 1);
    quick_s(arr, pivot + 1, high);
  }
}
void printArr(int arr[], int size) {
  for(int i = 0; i < size; i++){
    printf("%2d", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Original Array: ");
  printArr(arr, n);
  quick_s(arr, 0, n - 1);
  printf("Sotred array: ");
  printArr(arr, n);
  return 0;
}