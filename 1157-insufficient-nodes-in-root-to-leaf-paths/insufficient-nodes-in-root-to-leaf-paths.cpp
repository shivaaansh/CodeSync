/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* node, int sum, int limit) {
        if (!node) return NULL;

        sum += node->val;

        if (!node->left && !node->right) {
            if (sum < limit) return NULL;
            return node;
        }

        node->left = dfs(node->left, sum, limit);
        node->right = dfs(node->right, sum, limit);

        if (!node->left && !node->right) {
            return NULL;
        }

        return node;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, 0, limit);
    }
};