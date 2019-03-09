#include <vector>
#include <string>
using namespace std;

// it take 15 minute to write this code
// Runtime: 24 ms, faster than 9.68%,Memory Usage: 19.5 MB, less than 8.81%
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans,"",n,0,0);
        return ans;
    }

    void dfs(vector<string>& ans,string tmp,int n,int x,int y){
        if(x > n || y>n || x < y) return;
        if(tmp.length() == 2*n){
            ans.push_back(tmp);
            return;
        }
        tmp += '(';
        dfs(ans,tmp,n,x+1,y);
        tmp.erase(tmp.end()-1);
        tmp += ')';
        dfs(ans,tmp,n,x,y+1);
        tmp.erase(tmp.end()-1);
    }
};