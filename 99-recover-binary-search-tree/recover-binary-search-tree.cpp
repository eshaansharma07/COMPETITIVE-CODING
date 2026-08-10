class Solution {
public:

    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        // Left
        inorder(root->left);

        // Current
        if (prev != nullptr && prev->val > root->val) {

            // First violation
            if (first == nullptr) {
                first = prev;
            }

            // Second violation
            second = root;
        }

        prev = root;

        // Right
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        inorder(root);

        // Swap the incorrect values
        swap(first->val, second->val);
    }
};