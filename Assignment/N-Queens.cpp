class Solution {
public:
    vector<string> board;
    vector<vector<string>> result;
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

    void solve(int row, int n){
        if(row == n){
            result.push_back(board);
            return;
        }
        for(int c = 0 ; c < n ; c++){
            if(isSafe(row, c, n)){
                csafe[c] = 0;
                ldiag[row-c+(n-1)] = 0;
                rdiag[row+c] = 0;
                board[row][c] ='Q';
                solve(row+1, n);
                board[row][c] = '.';
                csafe[c] = 1;
                ldiag[row-c+(n-1)] = 1;
                rdiag[row+c] = 1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        csafe.assign(n, 1);
        ldiag.assign(2*n-1, 1);
        rdiag.assign(2*n-1, 1);
        board.assign(n, string(n, '.'));
        solve(0, n);
        return result;
    }
};