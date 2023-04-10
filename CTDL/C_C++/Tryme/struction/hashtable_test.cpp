#include <stdio.h>
#include <conio.h>
#include <iostream>
#define HASH_SIZE 11

    using namespace std;
struct Node{
    int value;
    Node* next;
};

Node* hash_table[HASH_SIZE];

int hash_Function(int data){
    return data % HASH_SIZE;
}

void insert(int data){
    int index = hash_Function(data);
    Node *temp = new Node;
    temp->value= data;
    if (hash_table[index] == NULL){
        hash_table[index] = temp;
    }
    temp->next= hash_table[index];
    hash_table[index]= temp;
}
int find(int data){
    int index = hash_Function(data);
    Node* curr = hash_table[index];
    while (curr){
        if (hash_table[index]->value == data)
            return 1;
        curr = curr->next;
    }
    return 0;
}
int main(){
    insert(21);
    insert(13);
    insert(2);
    int check = find(13);
    cout<<check;
    return 0;
}
