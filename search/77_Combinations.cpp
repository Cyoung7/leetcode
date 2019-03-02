#include<vector>

using namespace std;
//write this code cost 10 minute
// Runtime: 528 ms,Memory Usage: 167 MB
class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        dfs(ans,vector<int>(),1,n,k);
        return ans;
    }

    void dfs(vector<vector<int>>& ans,vector<int> tmp,int idx,int n,int k)
    {
        if (k == 0)
        {
            ans.push_back(tmp);
            return;
        }
        for(int i = idx; i <= n; i++)
        {
            tmp.push_back(i);
            dfs(ans,tmp,i+1,n,k-1);
            tmp.pop_back();
        }
    }
};