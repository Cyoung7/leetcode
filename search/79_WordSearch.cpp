#include <vector>
#include <string>
using namespace std;

// it take 30 minite to write this code
// Runtime: 24 ms, faster than 97.39% ,Memory Usage: 10.7 MB, less than 78.06% 
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        row = board.size();
        col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if (dfs(board,word,0,i,j)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board,const string& word,int d,int x,int y) {
        if (d == word.length()) {
            return true;
        }
        if (x < 0 || x >=row || y < 0 || y >= col ) {
            return false;
        }
        
        if (word[d] == board[x][y]) {
            char tmp = board[x][y];
            board[x][y] = 0;
            bool status = dfs(board,word,d+1,x+1,y)
                        ||dfs(board,word,d+1,x-1,y)
                        ||dfs(board,word,d+1,x,y+1)
                        ||dfs(board,word,d+1,x,y-1);
            board[x][y] = tmp;
            return status;
        }
        return false;
    }
    private:
        int col;
        int row;
};