#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// it take 30 minute to write this code
// Runtime: 4 ms, faster than 100.00%,Memory Usage: 9.2 MB, less than 51.48% 
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(),A.end());
        vector<int> used(A.size());
        int num = 0;
        dfs(A,vector<int>(),used,num);
        return num;
    }

    void dfs(vector<int> &A,vector<int> tmp,vector<int>& used,int& num){
        if(tmp.size() == A.size()){
            ++num;
            return;
        }
        for (int i = 0;i < A.size();i++){
            if(used[i]) continue;
            if((i > 0 && A[i] ==  A[i-1] && !used[i - 1])) continue;
            if(! tmp.empty() && !is_square(A[i],tmp.back())) continue;
            tmp.push_back(A[i]);
            used[i] = 1;
            dfs(A,tmp,used,num);
            used[i] = 0;
            tmp.pop_back();
        }
    }

    bool is_square(int i,int j){
        int s = sqrt(i+j);
        return s*s == (i+j);
    }
};