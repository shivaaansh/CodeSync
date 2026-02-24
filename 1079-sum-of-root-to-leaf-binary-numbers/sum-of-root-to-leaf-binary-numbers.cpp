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
    vector<vector<int>> rtl;
    void helper(TreeNode* root, vector<int> &v) {
        if(!root) return ;
        if(!root->left && !root->right) {
            v.push_back(root->val);
            rtl.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        helper(root->left, v);
        helper(root->right, v);
        v.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        int sum = 0;
        for(vector<int> &v : rtl) {
            int cur = 0;
            for(int i = v.size()-1; i >= 0; i--) {
                cur += pow(2, v.size() - 1 - i) * v[i];
            }
            sum += cur;
        }
        return sum;
    }
};