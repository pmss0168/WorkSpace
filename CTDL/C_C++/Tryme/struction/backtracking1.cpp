#include <iostream>
#define size 3
using namespace std;
bool check[size];
int arr[size];
void backtrack(int step){
    if (step > size){
        for (int i=0; i<size; i++){
            cout << arr[i] << "";
        }
        cout << endl;
        return;
    }
    for (int i=0; i< size; i++){
        if(check[i] == 0){
            arr[i] = 1;
            check[i] = 1;
            backtrack(step + 1);
            check[i] = 0;
        }
        else {
            arr[i] = 0;
            check[i] = 1;
            backtrack(step + 1);
            check[i] = 0;
        }
    }
       
}
int main(){
    backtrack(1);
    return 0;
}