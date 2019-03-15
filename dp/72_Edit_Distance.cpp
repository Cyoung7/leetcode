#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// Runtime: 24 ms, faster than 18.13%,Memory Usage: 11.3 MB, less than 31.33%
// DP
// Input:O(m)+O(n),Subproblems:O(mn), Depend on:O(1)*3,Time:O(mn),Space:O(mn)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        // result[i][j] := minDistance(word1[0:i - 1], word2[0:j - 1]);
        vector<vector<int>> result(len1 + 1, vector<int>(len2 + 1,0));
        for (int i = 0; i <= len1; i++) {
            result[i][0] = i;
        }
        for (int j = 0; j <= len2; j++) {
            result[0][j] = j;
        }
        for(int i = 1; i <= len1; i++) {
            for (int j = 1;j <= len2; j++) {
                int c = word1[i - 1] == word2[j - 1] ? 0 : 1;
                result[i][j] = min(result[i - 1][j - 1] + c,
                                    min(result[i - 1][j],result[i][j-1]) + 1);
            }
        }
        return result[len1][len2];
    }
};