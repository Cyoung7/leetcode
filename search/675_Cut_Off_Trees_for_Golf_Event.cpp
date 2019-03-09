#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

// it take 120 minute to write this code
// Runtime: 516 ms，Memory Usage: 154.1 MB
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        m_ = forest.size();
        n_ = forest[0].size();
        vector<tuple<int,int,int>> trees;
        for (int i = 0;i < m_; i++) {
            for (int j = 0;j < n_;j++) {
                if(forest[i][j] > 1) trees.emplace_back(forest[i][j],i,j);
            }
        }
        sort(trees.begin(),trees.end());
        int sx = 0;
        int sy = 0;
        int total_step = 0;
        for(int i =0 ;i < trees.size();i++) {
            int tx = get<1>(trees[i]);
            int ty = get<2>(trees[i]);
            int step = bfs(forest,sx,sy,tx,ty);
            if (step == INT_MAX) return -1;
            total_step += step;
            sx = tx;
            sy = ty;
        }
        return total_step;
    }  
     int bfs(const vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {

        static int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto visited = vector<vector<int>>(m_, vector<int>(n_, 0));

        queue<pair<int,int>> q;
        q.emplace(sx, sy);

        int steps = 0;
        while (!q.empty()) {
            // ++steps;
            int new_nodes = q.size();
            for (int i=0; i < new_nodes; i++) {
                auto node = q.front();
                q.pop();
                // Found the shortest path
                // cannot move this line to line 61,
                // 在sx,sy与tx,ty均相同的情况下，会多走两步
                if (sx == tx && sy == ty) 
                    return steps;
                const int cx = node.first;
                const int cy = node.second;
                for (int i = 0; i < 4; ++i) {
                    const int x = cx + dirs[i][0];
                    const int y = cy + dirs[i][1];
                    // // Found the shortest path
                    // if (x == tx && y == ty) 
                    //     return steps;
                    // Out of bound or unwalkable
                    if (x < 0 || x == m_ || y < 0 || y == n_
                     || !forest[x][y] || visited[x][y]) continue;
   
                    visited[x][y] = 1;                    
                    q.emplace(x, y);                
                }
            }
            ++steps;
        }
        return INT_MAX;
    }

private:
    int m_;
    int n_;

};

int main() {
    vector<vector<int>> m = {{2,3,4},{0,0,5},{8,7,6}};
    Solution sol = Solution();
    int ans = sol.cutOffTree(m);
    cout << ans << endl;
    return 0;
}