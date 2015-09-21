//Problem: https://leetcode.com/problems/word-ladder-ii/
#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        //step1: initialization
        unordered_set<string> forward;
        forward.insert(beginWord);
        wordList.erase(beginWord);
        unordered_set<string> backward;
        backward.insert(endWord);
        wordList.erase(endWord);

        //step2: 2-way BFS
        int wordLen = beginWord.length();
        unordered_map<string, vector<string> > edgeTo;
        bool is_forward = true;
        bool found = false;

        while (!forward.empty() && !backward.empty() && !found){
            if (forward.size() > backward.size()){
                swap(forward, backward);
                is_forward = !is_forward;
            }

            unordered_set<string> nexts;
            unordered_set<string>::iterator it;
            for (it = forward.begin(); it != forward.end(); ++it){
                string next = *it;
                for (int i = 0; i < wordLen; ++i){
                    char temp = next[i];
                    for (int j = 0; j < 26; ++j){
                        next[i] = 'a' + j;
                        if (backward.find(next) != backward.end())
                            found = true;
                        if (wordList.find(next) != wordList.end() || backward.find(next) != backward.end()){
                            nexts.insert(next);
                            is_forward ? edgeTo[next].push_back(*it) : edgeTo[*it].push_back(next);
                        }
                    }
                    next[i] = temp;
                }
            }
            for (it = nexts.begin(); it != nexts.end(); ++it)
                wordList.erase(*it);
            forward = nexts;
        }

        //step3: calculate and return answer
        vector<vector<string> > ret;
        if (found){
            ret.push_back(vector<string>(1, endWord));
            while (true){
                int n = ret.size();
                for (int i = n - 1; i >= 0; --i){
                    if (ret[i].back() == beginWord) continue;
                    for (int j = 0; j < edgeTo[ret[i].back()].size(); ++j){
                        ret[i].push_back(edgeTo[ret[i].back()][j]);
                        ret.push_back(ret[i]);
                        ret[i].pop_back();
                    }
                    swap(ret[i], ret.back());
                    ret.pop_back();
                }
                if (ret[0].back() == beginWord) break;
            }
            for (int i = 0; i < ret.size(); ++i)
                reverse(ret[i].begin(), ret[i].end());
        }

        return ret;
    }
};

int main(){
	Solution my_solution;
    string string_list[] = {"hot","dot","dog","lot","log"};
    unordered_set<string> wordList;
	cout << "length of string_list = " << sizeof(string_list) / sizeof(string_list[0]) << endl;
	for (int i = sizeof(string_list) / sizeof(string_list[0]) - 1; i >= 0; --i)
		wordList.insert(string_list[i]);
	vector<vector<string> > ret = my_solution.findLadders("hit", "cog", wordList);
	cout << "ret.size() = " << ret.size() << endl; 
	for (int i = 0; i < ret.size(); ++i){
		vector<string> cur = ret[i];
		for (int j = 0; j < cur.size(); ++j)
			cout << cur[j] << ", ";
		cout << endl;
	}
	return 0;
}