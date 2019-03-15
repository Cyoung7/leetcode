#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Memory Usage: 13.7 MB, less than 36.02%,Runtime: 560 ms, faster than 6.13% 
// DP, 不是很理解
// Input:O(n) + k,Subproblems:O(k),Depend on:O(n),Time:O(kn),Space:O(k)
// Running time: 16 ms
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = min coins to make up to amount i
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i)
                if (dp[i - coin] != INT_MAX)  
                    dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};