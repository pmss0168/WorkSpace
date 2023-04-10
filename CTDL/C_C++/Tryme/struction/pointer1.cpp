#include <iostream>
using namespace std;

int main(){
    int a = 69;
    int *pointer = &a;
    cout <<"Dia chi bien a la: "<< endl;
    cout << pointer << endl;
    cout << a << endl;
    *pointer = 80;
    cout << a << endl;
    return 0;
}