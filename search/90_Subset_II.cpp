#include <vector>
#include<algorithm>
using namespace std;
// it takes 9 minute to write the code
// Runtime: 16 ms,Memory Usage: 10 MB
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        dfs(ans,vector<int>(),nums,0);
        return ans;
    }
    void dfs(vector<vector<int>>& ans,vector<int>tmp,
                vector<int>nums,int start)
    {
        ans.push_back(tmp);
        for(int i=start;i < nums.size();i++)
        {
            if(i > start && nums[i] == nums[i-1]) continue;
            tmp.push_back(nums[i]);
            dfs(ans,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
};