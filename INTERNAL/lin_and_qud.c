#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MS 10

// int hashTable[MS], i;
//
// void iniHashTable(){
//     for(i = 0; i < MS; i++){
//         hashTable[i] = -1;
//     }
// }
// int hash(int key){
//     return key % MS;
// }
//
// int insert(int key){
//     int idx = hash(key);
//     while(hashTable[idx] != -1){
//         idx = (idx + 1) % MS;
//     }
//     hashTable[idx] = key;
// }
//
// int display(){
//     printf("--HashTable--\n");
//     for(int i = 0; i < MS; i++){
//             if(hashTable[i] != -1)
//         printf("hashTable[%d] = %d\n", i, hashTable[i]);
//     }
// }
int hashTable[MS], i;
void inihashTable() {
  for (i = 0; i < MS; i++) {
    hashTable[i] = -1;
  }
}
int hash(int key) { return key % MS; }

int insert(int key) {
  // int i = 0;
  int idx = hash(key);
  while (hashTable[idx] != -1) {
    // i++
    idx = (idx + 1) % MS;
    // idx = (idx + (int)pow(i ,2)) % MS;
  }
  hashTable[idx] = key;
}
int display() {
  printf("-HASHTABLE-\n");
  for (int i = 0; i < MS; i++) {
    if (hashTable[i] != -1) //{
      printf("hashTable[%d]: %d\n", i, hashTable[i]);
    //} else { printf("hashTable[%d]", i); }
  }
}
int main() {
  inihashTable();
  insert(13);
  insert(33);
  insert(53);
  insert(3);
  insert(43);
  display();
  return 0;
}