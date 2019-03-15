#include <vector>
#include <algorithm>
using namespace std;

// Runtime: 20 ms, faster than 84.45%,Memory Usage: 9.4 MB, less than 31.34%
// DP
// Input:O(n),Subproblems:O(n^2), Depend on:O(n),Time:O(n^2),Space:O(n^2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // dp[i][j]代表nums[i:j]能获得的最大钱数
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for (int l = 1;l <= n; l++) {
            for (int i = 1;i <= n - l + 1; i++) {
                int j = i + l - 1;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + nums[i-1] * nums[k] * nums[j+1] + dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
    }
};