#include <stdio.h>
#include <stdlib.h>
#define MS 10

int hashTable[MS], i;
void iniHashTable(){
    for(int i = 0; i < MS; i++){
        hashTable[i] = -1;
    }
}

int hash(int key){
    return key % MS;
}

void insert(int key){
    int idx = hash(key);
    while(hashTable[idx] != -1) {
        idx = (idx + 1) % MS;
    }
    hashTable[idx] = key; //Once an empty slot is found, the key is stored at that index
}
void display(){
    printf("--HashTable--\n");
    for(i=0; i<MS; i++){
        if(hashTable[i] != -1)
            printf("hashTable[%d] = %d\n",i,hashTable[i]);
    }
}
int main(){
    iniHashTable(); // Initialize the hash table
    insert(14);
    insert(34);
    insert(84);
    insert(24);
    insert(54);
    display();
    return 0;
}
