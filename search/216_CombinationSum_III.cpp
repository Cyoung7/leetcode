#include <vector>
using namespace std;

// Find all possible combinations of k numbers that add up to a number n, 
// given that only numbers from 1 to 9 can be used and each combination 
// should be a unique set of numbers.

// Note:
// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.

// Example 1:
// Input: k = 3, n = 7
// Output: [[1,2,4]]

// Example 2:
// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

// it takes 25 minute to write the code
// Runtime: 4 ms, Memory Usage: 9 MB
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        dfs(ans,vector<int>(),1,k,n);
        return ans;
    }
    void dfs(vector<vector<int>>& ans,vector<int> tmp,int idx,int k,int target)
    {   
        if (k == 0)
        {
            if(target == 0 ){
                ans.push_back(tmp);
            }
            return;
        }
        //用不超过9的数字
        for(int i=idx;i<10;i++){
            tmp.push_back(i);
            dfs(ans,tmp,i+1,k-1,target-i);
            tmp.pop_back();
        }
    }
};