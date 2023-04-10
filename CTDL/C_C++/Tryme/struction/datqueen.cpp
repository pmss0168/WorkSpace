#include <iostream>
#define SIZEBOARD 8
using namespace std;
int count = 0;
int a[SIZEBOARD];
void Queen(int a[], int row){
    if (row == SIZEBOARD){
        count ++;
        cout << count <<". ";
        for (int i=0; i<SIZEBOARD; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    else{
        //backtrack
        for (int i=0; i<SIZEBOARD; i++){
            bool check = 1;
            // kiem tra dat dc hay khong
            for (int j=0; j< row; j++){
                if((i == a[j])||(i == a[j]-j+row)||(i == a[j]+j-row)){
                    check = 0;
                }
            }
            // neu dat thanh cong
            if (check){
                a[row] = i;
                Queen(a,row+1);
            }
        }

    }
    
}
int main(){
    Queen(a,0);
    return 0;
}