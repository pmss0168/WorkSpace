#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 1, y = 2;
    cout <<"x before is: " << x <<" and y is: "<< y << endl;
    swap(&x,&y);
    cout <<"x after is: " << x <<" and y is: "<< y << endl;
    return 0;
}