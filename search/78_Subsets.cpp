#include <vector>
using namespace std;
// it takes 15 minute to write the code by reading solution.
// Runtime: 12 ms,Memory Usage: 9.5 MB
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(ans,vector<int>(),nums,0);
        return ans;
    }
    void dfs(vector<vector<int>>& ans,vector<int> tmp,
                vector<int> nums,int start)
    {
        ans.push_back(tmp);
        for(int i = start;i < nums.size();i++)
        {
            tmp.push_back(nums[i]);
            dfs(ans,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
};