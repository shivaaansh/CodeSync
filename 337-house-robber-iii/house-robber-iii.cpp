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
    vector<int> hr(TreeNode* root){
        vector<int> v(2,0);
        if(root == NULL) return v;
        vector<int> left = hr(root->left);
        vector<int> right = hr(root->right);
        v[0] = left[1] + root->val + right[1];
        v[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return v;
    }
    int rob(TreeNode* root) {
        vector<int> v = hr(root);
        return max(v[0], v[1]);
    }
};