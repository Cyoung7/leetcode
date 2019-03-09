#include<vector>
#include<string>
#include <set>
using namespace std;

// it take 90 minute to write this code
// Runtime: 8 ms, faster than 92.35%,Memory Usage: 9.8 MB, less than 74.73%
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0;
        int right = 0;
        
        for(const char c:s){
            if( c == '('){
                ++left;
            }
            else if(c == ')'){
                if(left > 0){
                    --left;
                }
                else{
                    ++right;
                }
            }
        }
        vector<string> ans;
        dfs(ans,0,left,right,s);
        return ans;   
    }
    void dfs(vector<string>& ans,int start,int left,int right,string& s) {
        if(left == 0 && right == 0) {
            if(isValid(s)) ans.push_back(s);
            return ;
        }
        for(int i = start;i < s.length(); ++i) {
            if(i != start && s[i] == s[i-1]) continue;
            if(s[i] == '(' || s[i] == ')') {
                string cur = s;
                cur.erase(i,1);
                if (left > 0 && s[i] =='('){
                    dfs(ans,i,left-1,right,cur);
                }
                if (right > 0 && s[i] == ')') {
                    dfs(ans,i,left,right-1,cur);
                }
            }
            
        }
        
    }
    bool isValid(string s){
        int count = 0;
        for(const char c:s){
            if (c == '(') count++;
            if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
};