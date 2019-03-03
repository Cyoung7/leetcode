#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// it take 15 minute to write the code
// Runtime: 68 ms,Memory Usage: 19.3 MB
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        dfs(ans,vector<int>(),set<int>(),nums);
        return ans;
    }
    void dfs(vector<vector<int>>& ans,vector<int>tmp,set<int>idx,vector<int>nums)
    {
        if(tmp.size() == nums.size()){
            ans.push_back(tmp);
            return;
        }
        for (int i = 0;i<nums.size();i++){
            // i > 0
            if(idx.find(i)!= idx.end() || (i>0 && idx.find(i-1)==idx.end() && nums[i]==nums[i-1])) continue;
            tmp.push_back(nums[i]);
            idx.insert(i);
            dfs(ans,tmp,idx,nums);
            tmp.pop_back();
            idx.erase(i);
        }
    }

};