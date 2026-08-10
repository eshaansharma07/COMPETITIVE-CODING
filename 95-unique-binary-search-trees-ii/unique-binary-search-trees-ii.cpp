class Solution {
public:

    vector<TreeNode*> generate(int start, int end) {

        vector<TreeNode*> result;

        // No nodes
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        // Try every value as root
        for (int rootValue = start; rootValue <= end; rootValue++) {

            // Generate all possible left subtrees
            vector<TreeNode*> leftTrees =
                generate(start, rootValue - 1);

            // Generate all possible right subtrees
            vector<TreeNode*> rightTrees =
                generate(rootValue + 1, end);

            // Combine every left subtree
            // with every right subtree
            for (TreeNode* left : leftTrees) {

                for (TreeNode* right : rightTrees) {

                    TreeNode* root =
                        new TreeNode(rootValue);

                    root->left = left;
                    root->right = right;

                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};