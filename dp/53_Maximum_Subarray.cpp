#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

// Runtime: 20 ms, faster than 10.58%，Memory Usage: 10.4 MB, less than 27.82%
// DP
// Input:O(n),Subproblems:O(n),Depend on:O(1),Time:O(n),Space:O(n)-->O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        // dp[i]代表[0,i]的最大和，必须包含nums第i个元素
        vector<int> dp(len,0);
        dp[0] = nums[0];
        int maxValue = dp[0];

        for(int i = 1;i < len; i++) {
            // 每次计算加上本次元素
            if (dp[i-1] > 0) {
                dp[i] = dp[i - 1] + nums[i];
            }else {
                dp[i] = nums[i];
            }
            maxValue = max(maxValue,dp[i]);
        }
        return maxValue;
    }
};