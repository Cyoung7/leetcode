#include <vector>
#include <utility>
#include <cmath>
using namespace std;

// Memory Usage: 11 MB, less than 56.86%,Runtime: 12 ms, faster than 76.11%
// DP
// Input:O(n^2),Subproblems:O(kn^2),Depend on:O(1),Time:O(kn^2),Space:O(kn^2) --> O(n^2)
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        // dp[k][i][j] 表示坐标(i,j)走k步留在棋盘内的所有可能性
        vector<vector<double>> dp0(N, vector<double>(N, 0.0));
        dp0[r][c] = 1.0;

        int dirs[8][2] = {{1, 2}, {-1, -2}, {1, -2}, {-1, 2},
                          {2, 1}, {-2, -1}, {2, -1}, {-2, 1}};

        for (int k = 0; k < K; k++) {
            vector<vector<double>> dp1(N, vector<double>(N, 0.0));

            for (int i = 0;i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int m = 0; m < 8; m++) {
                        int x = i + dirs[m][0];
                        int y = j + dirs[m][1];
                        if (x < 0 || y < 0 || x >= N || y >= N) {
                            continue;
                        }
                        dp1[i][j] += dp0[x][y];
                    }
                }
            }
            swap(dp0,dp1);
        } 
        double total = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                total += dp0[i][j];
            }
        }
        return total / pow(8,K);
    }
};