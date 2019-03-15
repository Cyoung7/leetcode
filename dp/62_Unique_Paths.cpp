#include <vector>
using namespace std;

// Runtime: 4 ms, faster than 100.00% ,Memory Usage: 8.8 MB, less than 10.02%
// DP
// Input:O(mn),Subproblems:O(mn),Depend on:O(1),Time:O(mn),Space:O(mn) --> O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        // f[i][j]:代表到达坐标(i,j)共有多少种走法
        vector<vector<int>> f(n+1, vector<int>(m+1,0));
        f[1][1] = 1;
        for (int i = 1;i <= n; i++) {
            for (int j = 1;j <= m; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                else {
                    f[i][j] = f[i-1][j] + f[i][j-1];
                }
            }
        }
        return f[n][m];
    }
};