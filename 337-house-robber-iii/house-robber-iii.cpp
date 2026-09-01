class Solution {
public:
    unordered_map<TreeNode*, int> dp[2];
    int rob(TreeNode* root, bool canRob = true) {
        if (!root){
            return 0;
        }
        int state = canRob ? 1 : 0;
        if (dp[state].count(root)){
            return dp[state][root];
        }
        int dontRob = rob(root->left, true) + rob(root->right, true);
        int robRoot = 0;
        if (canRob) {
            robRoot = root->val + rob(root->left, false) + rob(root->right, false);
        }
        return dp[state][root] = max(dontRob, robRoot);
    }
};