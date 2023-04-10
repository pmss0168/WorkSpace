#include <iostream>
#define M 7
using namespace std;
void Init(int board[][M]){
    for (int i=0; i<M; i++)
        for (int j=0; j<M; j++)
            board[i][j]=0;
    
}
bool Check(int i, int j){
    return ((i>=0) && (i<M) && (j>=0) && (j<M));
}
void Show(int board[][M]){
    for (int i=0; i<M; i++){
        for (int j=0; j<M; j++){
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }   
}
void backtrack(int step, int i, int j, int board[][M], int *I, int *J, int &ok){
    int m, inext, jnext;
    for (m=0; m<8; m++){
        inext = i+ I[m];
        jnext = j+ J[m];
        if (Check(inext,jnext)&&(board[inext][jnext]==0)){
            board[inext][jnext] = step + 1;
            if (step == M*M-1)
                ok = 1;
            else{
                backtrack(step + 1, inext, jnext, board, I, J, ok);
                if (!ok)
                    board[inext][jnext] = 0;
            }
        }
    }
}
int main(){
    int board[M][M], ok=0, i=2, j=0;
    int I[8] = { -2, -1, 1, 2, 2, 1,-1, -2 };
    int J[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    Init(board);
    board[i][j]=1;
    backtrack(1, i, j, board, I, J, ok);
    cout <<"======================" << endl;
    if (ok)
        Show(board);
    else
        cout << "Deo giai duoc!!!" << endl;
    return 0;
}
        