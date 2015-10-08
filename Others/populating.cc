#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root, TreeLinkNode *goal) {
        if (root == NULL) return;
        root->next = NULL;
        dfs(root, goal);
    }
    
    void dfs(TreeLinkNode *root, TreeLinkNode *goal){
        if ((root->left == NULL) and (root->right == NULL)) return;
        
        //step1: choose node [cur] need to be connected
        if ((root->left != NULL) and (root->right != NULL))
            root->left->next = root->right;
        TreeLinkNode *cur;
        if (root->left != NULL) cur = root->left;
        if (root->right != NULL) cur = root->right;
        cur->next = NULL;
        
        //step2: choose node [choose] to connect with [cur]
        if (root == goal){
            cout << goal->val << endl;
            cout << "left = " << root->left->val << endl;
            cout << "right = " << root->right->val << endl;
        }
        TreeLinkNode *bro = root->next;
        while (bro != NULL){
            if (root == goal){
                cout << "bro = " << bro->val << endl;
                cout << "left? = " << (bro->left == NULL) << endl;
                cout << "right? = " << (bro->right == NULL) << endl;

            }

            if ((bro->left == NULL) and (bro->right == NULL)) bro = bro->next;
            else{
                TreeLinkNode *choose;
                if (bro->right != NULL) choose = bro->right;
                if (bro->left != NULL) choose = bro->left;
                cur->next = choose;
                break;
            }
        }
        
        //step3: continue to dfs
        if (root->right != NULL) dfs(root->right, goal);
        if (root->left != NULL) dfs(root->left, goal);
    }
};

int main(){
    TreeLinkNode *root = new TreeLinkNode(2);
    TreeLinkNode *n1 = new TreeLinkNode(1);
    TreeLinkNode *n2 = new TreeLinkNode(3);
    root->left = n1, root->right = n2;
    TreeLinkNode *n3 = new TreeLinkNode(0);
    TreeLinkNode *n4 = new TreeLinkNode(7);
    n1->left = n3, n1->right = n4;
    TreeLinkNode *n5 = new TreeLinkNode(9);
    TreeLinkNode *n6 = new TreeLinkNode(1);
    n2->left = n5, n2->right = n6;
    TreeLinkNode *n7 = new TreeLinkNode(2);
    n3->left = n7;
    TreeLinkNode *n8 = new TreeLinkNode(1);
    TreeLinkNode *n9 = new TreeLinkNode(0);
    n4->left = n8, n4->right = n9;
    TreeLinkNode *n10 = new TreeLinkNode(8);
    TreeLinkNode *n11 = new TreeLinkNode(8);
    n6->left = n10, n6->right = n11;
    TreeLinkNode *n12 = new TreeLinkNode(7);
    n9->left = n12;
    Solution test;
    test.connect(root, n4);
}

