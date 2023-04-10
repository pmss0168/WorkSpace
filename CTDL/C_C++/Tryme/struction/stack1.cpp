#include <iostream>
#define SIZEMAX 4
int top = -1;
int arr[SIZEMAX];
bool is_full()
{
    if (top >= SIZEMAX)
        return true;
    else
        return false;
}
void push(int data)
{
    if (is_full())
        return;
    else
    {
        top++;
        arr[top] = data;
    }
}
bool is_emptys()
{
    if (top == -1)
        return true;
    else
        return false;
}
void pop()
{
    if (is_emptys())
        return;
    else
        top--;
}
int current_size()
{
    return top + 1;
}
int peak()
{
    return arr[top];
}
using namespace std;

int main()
{
    push(100);
    push(12);
    push(76);
    pop();
    push(10);
    cout << peak();
    push(11);
    push(20);
    return 0;
}