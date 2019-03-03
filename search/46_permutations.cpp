#include<vector>
#include <set>
using namespace std;

// Given a collection of distinct integers, return all possible permutations.

// Example:
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

// it takes 20 minute to write the code
// Runtime: 24 ms,Memory Usage: 12.8 MB
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(ans,vector<int>(),set<int>(),nums);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans,vector<int>tmp,set<int> idx,
             vector<int>&nums)
    {
        if(tmp.size()==nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(idx.find(i) != idx.end()) continue;
            tmp.push_back(nums[i]);
            idx.insert(i);
            dfs(ans,tmp,idx,nums);
            tmp.pop_back();
            idx.erase (i);
        }
    }
};