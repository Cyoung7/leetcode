#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

// Input: S = "3z4"
// Output: ["3z4", "3Z4"]

// Input: S = "12345"
// Output: ["12345"]
// Note:

// S will be a string with length between 1 and 12.
// S will consist only of letters or digits.

// Runtime: 12 ms, faster than 100.00%,Memory Usage: 14.2 MB, less than 33.00% 
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        dfs(ans,0,S);
        return ans;
    }
    void dfs(vector<string>& ans,int idx,string S){
        if(idx == S.length()){
            ans.push_back(S);
            return;
        }
        // wrong format:'0' <= S[idx] <='9'
        if('0' <= S[idx] && S[idx] <='9'){
            dfs(ans,idx+1,S);
            return;
        }
        //输出结果相对S而言，都从S首部开始，个数、顺序均不变，所以不需用for
        S[idx] = tolower(S[idx]);
        dfs(ans,idx+1,S);
 
        S[idx] = toupper(S[idx]);
        dfs(ans,idx+1,S);
    }
};

int main(){
    Solution* sol = new Solution();
    string a = "a1b2";
    vector<string> ans = sol->letterCasePermutation(a);
    for (int i=0;i < ans.size();i++){
        cout << ans[i]  << endl;
    }
    
    return 0;
}