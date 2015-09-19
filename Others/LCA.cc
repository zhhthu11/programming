#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ret = root;
        if (root == NULL) return ret;
        string left_path = find(root, p);
        string right_path = find(root, q);
        int len = left_path.size();
        if (right_path.size() < len) len = right_path.size();
        for (int i = 0; i < len; ++i){
            if (left_path[i] != right_path[i]) break;
            if (left_path[i] == '0') ret = ret->left;
            if (left_path[i] == '1') ret = ret->right;
        }
        return ret;
    }

    string find(TreeNode* root, TreeNode* goal){
        if (root == goal) return "";
        if (root->left){
            string left_path = find(root->left, goal);
            if (left_path != "-1") return "0" + left_path;
        }
        if (root->right){
            string right_path = find(root->right, goal);
            if (right_path != "-1") return "1" + right_path;
        }
        return "-1"; //not find
    }
};

int main(){
    Solution my_solution;
    TreeNode *root = new TreeNode(5);
    TreeNode *p = new TreeNode(1), *q = new TreeNode(10);
    root->left = p;
    root->right = q;
    TreeNode *ret = my_solution.lowestCommonAncestor(root, p, q);
    cout << "ret value = " << ret->val << endl;
}
