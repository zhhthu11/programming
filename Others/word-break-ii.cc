#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if ((s.size() == 0) or (wordDict.size() == 0)) return vector<string>();
        unordered_map<string, int> dict;
        for (unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); ++it)
            dict[*it] = 1;
        int n = s.size();
        int **a = new int*[n + 1];
        for (int i = 0; i < n + 1; ++i) a[i] = new int[n + 1];
        for (int i = 0; i < n + 1; ++i) a[i][0] = 0;
        a[n][0] = -1;
        for (int i = n - 1; i >= 0; --i){
            string cur = "";
            for (int j = i; j < n; ++j){
                cur += s[j];
                if (a[j + 1][0] == 0) continue;
                if (dict[cur] == 1)
                    a[i][++a[i][0]] = j + 1;
            }
        }
        vector<string> ret = dfs(a, 0, s);
        reverse(ret.begin(), ret.end());
        return ret;
    }

    vector<string> dfs(int **a, int status, string s){
        vector<string> ret;
        for (int i = 1; i <= a[status][0]; ++i){
            int next = a[status][i];
            string cur = s.substr(status, next - status);
            if (next == s.size()){
                ret.push_back(cur);
                continue;
            }
            vector<string> tmp = dfs(a, next, s);
            for (vector<string>::iterator it = tmp.begin(); it != tmp.end(); ++it)
                ret.push_back(cur + " " + *it);
        }
        return ret;
    }
};

int main(){
    Solution test;
    string s = "catsanddog";
    unordered_set<string> wordDict;
    wordDict.insert("cat");
    wordDict.insert("cats");
    wordDict.insert("and");
    wordDict.insert("sand");
    wordDict.insert("dog");
    vector<string> ret = test.wordBreak(s, wordDict);
    for (vector<string>::iterator it = ret.begin(); it != ret.end(); ++it)
        cout << (*it) << endl;
    return 0;
}