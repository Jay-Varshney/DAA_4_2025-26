#include <bits/stdc++.h>
using namespace std;

vector<string> board;
vector<int> csafe;
vector<int> ldiag;
vector<int> rdiag;

bool isSafe(int row, int col, int n){
    if(csafe[col] == 0){
        return false;
    }
    if(ldiag[row-col+(n-1)] == 0){
        return false;
    }
    if(rdiag[row+col] == 0){
        return false;
    }
    return true;
}

bool solve(int row, int n){
    if(row == n){
        return true;
    }
    for(int c = 0 ; c < n ; c++){
        if(isSafe(row, c, n)){
            csafe[c] = 0;
            ldiag[row-c+(n-1)] = 0;
            rdiag[row+c] = 0;
            board[row][c] ='J';
            if(solve(row+1, n)){
                return true;
            }
            board[row][c] = '.';
            csafe[c] = 1;
            ldiag[row-c+(n-1)] = 1;
            rdiag[row+c] = 1;
        }
    }
    return false;
}

int main(){
    int n;
    cout << "Enter size of the board\n";
    cin >> n;
    csafe.assign(n, 1);
    ldiag.assign(2*n-1, 1);
    rdiag.assign(2*n-1, 1);
    board.assign(n, string(n, '.'));
    solve(0, n);
    for(int i= 0 ; i< n ;i++){
        for(int j =0 ; j < n ; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}