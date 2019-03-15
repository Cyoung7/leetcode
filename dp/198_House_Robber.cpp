#include <vector>
#include <algorithm>
using namespace std;

// DP
// Input:O(n),Subproblems:O(n),Depend on:O(1),Time:O(n),Space:O(n)-->O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int OptionOne = 0;
        int OptionTwo = 0;
        // res[i] 代表nums[0:i]能获得的最大金额
        int res = 0;
        for (int i = 0; i < len; i++) {
            res = max(OptionOne+nums[i],OptionTwo);
            OptionOne = OptionTwo;
            OptionTwo = res;
        }
        return res;
    }
};