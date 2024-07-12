#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MS 10

int hashTable[MS], i;
void iniHashTable(){
  for(int i = 0; i< MS; i++){
    hashTable[i] = -1;
  }
}

int hash(int key) {
  return key % MS;
}

void insert(int key) {
  int i = 0;
  int idx = hash(key);
  while(hashTable[idx] != -1){
    i++;
    idx = (idx + (int)pow(i, 2)) % MS;
  }
  hashTable[idx] = key;
}

void display() {
  printf("--HASH TABLE--");
  for(i = 0; i < MS; i++){
    if(hashTable[i] != -1){
      printf("hashTable[%d] = %d\n", i, hashTable[i]);
    } else {
      printf("hashTable[%d] = %d\n", i);
    }
  }
}

int main(){
  iniHashTable();
  insert(14);
  insert(17);
  insert(19);
  insert(23);
  display();
  return 0;
}