#include <iostream>
#define MAX_SIZE 10
using namespace std;

int queue[MAX_SIZE];
int front = 0, rear = 0;

//========================
void Endqueue(int data){
    // check
    if ((rear == MAX_SIZE))
        cout <<"Full"<< endl;
    else{
        // them 1 phan tu
        queue[rear] = data;
        rear++;
    }
}
void Dequeue(){
    // kiem tra rong
    if (front == rear)
        cout <<"Queue empty"<< endl;
    else{
        // xoa phan tu khoi hang doi
        queue[front] = 0;
        front++;
    }
}
int Front(){
    return queue[front];
}
int Size(){
    return rear - front;
}
//========================
int main(){
    Endqueue(8);
    Endqueue(12);
    Endqueue(1572);
    Endqueue(142);
    Endqueue(12424);
    Dequeue();
    Endqueue(100);
    cout << Front();
    cout << Size();
    return 0;
}