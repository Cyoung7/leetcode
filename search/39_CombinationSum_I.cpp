#include <vector>
#include <algorithm>
using namespace std;
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

int main(){
	
}