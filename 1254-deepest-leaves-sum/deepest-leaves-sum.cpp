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
    int maxi = 0;
    int f(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int l = f(root->left);
        int r = f(root->right);
        return 1 + max(l, r);
    }
    int f(TreeNode* root, int h) {
        if(root == NULL) return 0;
        if(h == maxi) {
            return root->val;
        }
        int left = f(root->left, h + 1);
        int right = f(root->right, h + 1);
        return left + right;
    }
    int deepestLeavesSum(TreeNode* root) {
        maxi = f(root);
        return f(root, 1);
    }
};