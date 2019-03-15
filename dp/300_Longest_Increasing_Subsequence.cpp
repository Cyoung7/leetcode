#include <vector>
#include <algorithm>
using namespace std;

// Memory Usage: 8.8 MB, less than 17.63%,Runtime: 44 ms, faster than 46.46%
// DP,与53题有细微差别(T53连续substre，T300非连续substr)，导致时间复杂度不同
// Input:O(n),Subproblems:O(n),Depend on:O(n),Time:O(n^2),Space:O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        //dp[i]代表nums[0:i]最长增量substr长度
        vector<int> dp(len,1);

        for (int i = 0;i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i],dp[j] + 1);
                }   
            }
        }
        int maxLen = 0;
        for(int i = 0;i < len; i++){
            maxLen = max(maxLen,dp[i]);
        }
        return maxLen;
    }
};