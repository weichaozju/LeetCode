/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

// The key observation is that the unsurrounded 'O' regions must have cells along
// one of the four edges of the square
// by Ke Hu (mrhuke@gmail.com) Apr. 2013
// O(n^2) time, O(n^2) space solution
class Solution {
public:

    void fill(vector<vector<char>> &board, int i, int j, queue<int> &q)
    {
        if (i >= 0 && i < board.size() && j >= 0 && j < board.size() && board[i][j] == 'O'){
            board[i][j] = '.';
            q.push(i*board.size() + j);
        }
    }

    void bfs(vector<vector<char>> &board, int i, int j, queue<int> &q)
    {
        fill(board, i, j, q);
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            int r = cur / board.size(), c = cur % board.size();
            fill(board, r-1, c, q);
            fill(board, r+1, c, q);
            fill(board, r, c-1, q);
            fill(board, r, c+1, q);
        }
    }

    void solve(vector<vector<char>> &board) {
        if (board.empty()) return;
        
        queue<int> q;
        
        for( int i = 0; i < board.size(); ++i){
            bfs(board, 0, i, q);
            bfs(board, board.size()-1, i, q);
        }
        
        for( int i = 1; i < board.size()-1; ++i){
            bfs(board, i, 0, q);
            bfs(board, i, board.size()-1, q);
        }
        
        for (int i = 0; i < board.size(); ++i){
            for ( int j = 0; j < board.size(); ++j){
                if (board[i][j] == '.') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
