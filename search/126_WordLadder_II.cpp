#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// BFS + DFS
// it take 60 minute to write this code
// Runtime: 200 ms, beats 63.49 
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if( !dict.count(endWord)) return {};
        dict.erase(beginWord);
        dict.erase(endWord);

        unordered_map<string, int> steps{{beginWord,1}};
        unordered_map<string, vector<string>> parents;
        queue<string> q;
        q.push(beginWord);

        vector<vector<string>> ans;

        const int l = beginWord.length();
        int step = 0;
        bool found = false;

        while(!q.empty() && !found) {
            ++step;
            for (int size = q.size();size > 0;size--) {
                const string p = q.front();q.pop();
                string w = p;
                for (int i = 0; i < l; i++) {
                    const char c = w[i];
                    for (int j = 'a';j <= 'z';j++) {
                        if (c == j) continue;
                        w[i] = j;
                        if (w == endWord) {
                            parents[w].push_back(p);
                            found = true;
                        }
                        else {
                            // Not a new word, but another transform
                            // with the same number of steps
                            if (steps.count(w) && step < steps[w]) {
                                parents[w].push_back(p);
                            }
                        }
                        if(!dict.count(w)) continue;
                        dict.erase(w);
                        q.push(w);
                        steps[w] = steps[p] + 1;
                        parents[w].push_back(p);
                    }
                    w[i] = c;
                }
            }
        }
        if (found) {
            vector<string> cur{endWord};
            dfs(ans,endWord, beginWord, parents, cur);
        }
        return ans;
    }

    void dfs(vector<vector<string>>& ans,const string& word,const string& beginWord,
                const unordered_map<string, vector<string>>& parents,vector<string>& cur) {
        if(word == beginWord) {
            ans.push_back(vector<string>(cur.rbegin(),cur.rend()));
            return;
        }
        for(const string& p : parents.at(word)) {
            cur.push_back(p);
            dfs(ans,p, beginWord, parents, cur);
            cur.pop_back();
        }

    }
};