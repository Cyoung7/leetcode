#include <vector>
#include <algorithm>
using namespace std;

// Given a set of candidate numbers (candidates) (without duplicates) and 
// a target number (target), find all unique combinations in candidates where
//  the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of
//  times.
// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]

// Example 2:
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]


// Runtime: 36 ms,Memory Usage: 15.2 MB
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
		sort(candidates.begin(),candidates.end());
		dfs(ans,candidates,0, vector<int>(),target);
		return ans;
    }
	void dfs(vector<vector<int>>& ans,vector<int>candidates, int idx,
					vector<int> tmp,int target){
		if (target == 0){
			ans.push_back(tmp);
			return;
		}
		for(int i=idx;i<candidates.size();i++){
			if (target < candidates[i]) return;
			tmp.push_back(candidates[i]);
			dfs(ans,candidates,i,tmp,target-candidates[i]);
			tmp.pop_back();
		}
	}
};
