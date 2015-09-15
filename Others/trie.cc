#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode** children_;
    bool is_word_;
    // Initialize your data structure here.
    TrieNode() {
        children_ = new TrieNode*[26];
        is_word_ = false;
    }
    ~TrieNode(){
        for (int i = 0; i < 26; ++i)
            delete children_[i];
        delete[] children_;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i){
            if (cur->children_[word[i] - 'a'] == NULL)
                cur->children_[word[i] - 'a'] = new TrieNode();
            cur = cur->children_[word[i] - 'a'];
        }
        cur->is_word_ = true;
        cout << "insert = " << word << endl;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i){
            if (cur->children_[word[i] - 'a'] == NULL)
                return false;
            cur = cur->children_[word[i] - 'a'];
        }
        return cur->is_word_;    
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); ++i){
            if (cur->children_[prefix[i] - 'a'] == NULL)
                return false;
            cur = cur->children_[prefix[i] - 'a'];
        }
        return true;        
    }

private:
    TrieNode* root;
};

int main(){
    Trie trie;
    trie.insert("honghui");
    cout << "Search hong = " << trie.search("hong") << endl;
    cout << "Search honghui = " << trie.search("honghui") << endl;
    cout << "Search prefix hong = " << trie.startsWith("hong") << endl;
    cout << "Search prefix zhang = " << trie.startsWith("zhang") << endl;
}