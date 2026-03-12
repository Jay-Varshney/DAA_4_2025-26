class Solution {
public:
    
    bool solve(vector<vector<char>>& board, string w, int i, int j, int idx, vector<vector<bool>>& visited){
        if(idx >= w.length()){
            return true;
        }
        vector<pair<int, int>> p = {
            {i, j-1},
            // {i-1, j-1},
            {i-1, j},
            // {i-1, j+1},
            {i, j+1},
            // {i+1, j+1},
            {i+1, j},
            // {i+1, j-1}
        };
        // pair<int, int> p1 = {i-1, j};
        // pair<int, int> p2 = {i-1, j-1};
        // pair<int, int> p3 = {i, j-1};
        // pair<int, int> p4 = {i+1, j-1};
        // pair<int, int> p4 = {i+1, j};
        // pair<int, int> p4 = {i+1, j+1};
        // pair<int, int> p4 = {i, j+1};
        // pair<int, int> p8 = {i-1, j+1};
        for(auto i:p){
            int a = i.first;
            int b = i.second;
            if(a >= board.size() || a < 0 || b >=board[0].size() || b < 0){
                continue;
            }else{
                if(board[a][b] == w[idx] && !visited[a][b]){
                    visited[a][b] = true;
                    if(solve(board, w, a, b, idx+1, visited)){
                        return true;
                    }
                    visited[a][b] = false;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i =0; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = true;
                    if(solve(board, word, i, j, 1, visited)){
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};