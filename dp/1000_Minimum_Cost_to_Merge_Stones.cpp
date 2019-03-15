#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// it take 60 minute to write this code
// Runtime: 12 ms, faster than 56.24%,Memory Usage: 12.1 MB, less than 100.00%
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        const int n = stones.size();
        if ((n - 1) % (K - 1)) return -1;

        const int kInf = 1e9;
        vector<int> sums(n + 1);
        for (int i = 0;i < n; ++i) {
            sums[i + 1] = sums[i] + stones[i];
        }

        // dp[i][j][k] := min cost to merge subarray i~j into k piles.
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(K + 1,kInf)));
        for (int i = 0; i < n; ++i) {
            dp[i][i][1] = 0;
        }

        for (int l = 2; l <= n; ++l) { // subproblem length
            for (int i = 0; i <= n - l; ++i) { // start
                int j = i + l - 1; // end
                for (int k = 2; k <= K; ++k) { // piles
                    for (int m = i; m < j; m += K - 1) { // split point
                        dp[i][j][k] = min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
                    }
                }
                dp[i][j][1] = dp[i][j][K] + sums[j + 1] - sums[i];
            }
        }  
        return dp[0][n-1][1];
    }
};

// it take 30 minute to write this code
// Runtime: 8 ms, faster than 74.12% ,Memory Usage: 9.5 MB, less than 100.00% 
class Solution1 {
public:
  int mergeStones(vector<int>& stones, int K) {

    const int n = stones.size();
    if ((n - 1) % (K - 1)) return -1;
        
    vector<int> sums(n + 1);
    for (int i = 0; i < stones.size(); ++i) {
        sums[i + 1] = sums[i] + stones[i];
    }
    const int kInf = 1e9;

    vector<vector<int>> dp(n, vector<int>(n, kInf));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
    }


    for (int l = 2; l <= n; ++l) {// subproblem length 
        for (int i = 0; i <= n - l; ++i) { // start        
            int j = i + l - 1; // end
            for (int m = i; m < j ; m += K - 1) {// split point
                dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
            }
            // If the current length can be merged into 1 pile
            // The cost is independent of the merge orders.
            if ((l - 1) % (K - 1) == 0) {
                dp[i][j] += sums[j + 1] - sums[i];
            }
        }
    }
    return dp[0][n-1];
  }
};


int main() {
    vector<int> a = {3,2,4,1};
    int K = 2;
    Solution* sol = new Solution();
    int ans = sol->mergeStones(a,K);
    return 0;
}