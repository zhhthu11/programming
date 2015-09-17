vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> ret;
    vector<vector<vector<TreeNode*>>> dp(n,vector<vector<TreeNode*>>(n));
    helper(1,n,ret,dp);
    return ret;
}

void helper(int start, int end, vector<TreeNode*> &ret,vector<vector<vector<TreeNode*>>> &dp) {
    if (start > end) {
        ret.push_back(NULL); return;
    }
    if (!dp[start-1][end-1].empty())  {
        ret = dp[start-1][end-1]; return;
    }
    for (int i = start; i <= end; ++i) {
        vector<TreeNode*> left, right;
        helper(start, i-1,left,dp);
        helper(i+1,end,right,dp);
        for(int j = 0; j < left.size(); ++j) {
            for (int k = 0; k < right.size(); ++k) {
                TreeNode* node = new TreeNode(i);
                node->left = left[j];
                node->right = right[k];
                ret.push_back(node);
            }
        }
    }
    dp[start-1][end-1] = ret;
}