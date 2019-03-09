#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

// BFS
//it takes 30 minute to write this code
// Runtime: 200 ms, faster than 81.58%,Memory Usage: 23.7 MB, less than 59.55%
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        const int h = matrix.size();
        const int w = matrix[0].size();
        for (int i = 0;i < h;i++) {
            for (int j = 0;j < w ;j++) {
                if (! matrix[i][j]) q.push({i,j});
                else matrix[i][j] = INT_MAX ;
            }
        }
        const vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            // cout << q.size() << endl;
            for(pair<int,int> dir : dirs) {
                int x = p.first + dir.first;
                int y = p.second + dir.second;
                if (x < 0 || x >= h || y < 0 || y >= w || matrix[x][y] <= (matrix[p.first][p.second]+1)) continue;
                // cout << matrix[x][y] << ' ' << matrix[p.first][p.first] << endl;
                matrix[x][y] = matrix[p.first][p.second] + 1;
                q.push({x,y});
                
            }
        }
        return matrix;
    }
};

int main() {
    vector<vector<int>> m = {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    Solution sol = Solution();
    vector<vector<int>> ans = sol.updateMatrix(m);
    return 0;
}