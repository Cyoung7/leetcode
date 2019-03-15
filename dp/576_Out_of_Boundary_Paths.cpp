#include <vector>

using namespace std;

// Runtime: 24 ms, faster than 38.42%,Memory Usage: 12.3 MB, less than 45.45%
// DP
// Input:O(mn),Subproblems:O(kmn),Depend on:O(1),Time:O(kmn),Space:O(kmn) --> O(mn)
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        constexpr int KMod = 1000000007;

        //dp[s][i][j]:从坐标(i,j)开始，s步能走出方阵的所有可能性
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));

        vector<int> dirs = {-1,0,1,0,-1};
        for (int s = 1; s <= N;s++) {
            for (int y = 0; y < m; y++) {
                for (int x = 0; x < n; x++) {
                    for (int d = 0; d < 4; d++) {
                        int tx = x + dirs[d];
                        int ty = y + dirs[d + 1];
                        // 如果必须走S步(小于S步走出去不算)才能出去，此if条件能在S=1的时候执行
                        if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
                            dp[s][y][x] += 1;
                        }else {
                            dp[s][y][x] = (dp[s][y][x] + dp[s - 1][ty][tx]) % KMod;
                        }
                    }
                }
            }
        }
        return dp[N][i][j];
    }
};