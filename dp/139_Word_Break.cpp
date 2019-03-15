#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Runtime: 20 ms, faster than 54.06%,Memory Usage: 16 MB, less than 18.03% 
// DP
// Input:O(n),Subproblems:O(n),Depend on:O(n),Time:O(n^2),Space:O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        // dp[i]代表s[0:i]是否能由wordDict中的单词构成
        vector<bool> dp(len+1,false);
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <= i - 1; j++) {
                const string right = s.substr(j,i-j);
                if(dp[j] && dict.count(right)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

int main(){
    string s = "leetcode";
    vector<string> w = {"leet","code"};
    Solution sol = Solution();
    bool a = sol.wordBreak(s,w);
    return 0;
}