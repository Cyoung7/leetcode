#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

// it take 30 minute to write this code 
// Runtime: 96 ms, faster than 73.27%,Memory Usage: 13.1 MB, less than 65.45%
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int l = beginWord.length();
        int step = 0;

        while(!q.empty()) {
            ++step;
            for (int size = q.size();size>0; size--) {
                string w = q.front();
                q.pop();
                for (int i = 0;i< l;i++) {
                    char c = w[i];
                    for(int j = 'a';j <='z';j++) {
                        if (j == c) continue;
                        w[i] = j;
                        if (w == endWord) return step + 1;
                        if ( !dict.count(w)) continue;
                        dict.erase(w);
                        q.push(w);
                    }
                    w[i] = c;
                }
            }
        }
        return 0;
    }
};

// Bidirectional BFS
// it take 30 minute to write this code
// Runtime: 28 ms, faster than 99.83%,Memory Usage: 13 MB, less than 74.60%
class Solution1 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(! dict.count(endWord)) return 0;
        int l = beginWord.length();

        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        int step = 0;

        while(!q1.empty() && !q2.empty()) {
            ++step;
            //Always expend the smaller queue first
            if(q1.size() > q2.size()) {
                std::swap(q1,q2);
            }
            unordered_set<string> q;
            for (string w:q1) {
                for (int i = 0;i < l;i++) {
                    char c = w[i];
                    for (int j = 'a'; j <= 'z';j++) {
                        if (c == j) continue;
                        w[i] = j;
                        if (q2.count(w)) return step + 1;
                        if (! dict.count(w)) continue;
                        dict.erase(w);
                        q.insert(w);
                    }
                    w[i] = c;
                }
            }
            std::swap(q,q1);
        }
        return 0;
    }
};