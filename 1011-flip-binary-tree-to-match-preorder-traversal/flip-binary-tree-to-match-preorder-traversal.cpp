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
    vector<int> ans;
    bool ok = true;

    void f(TreeNode* root, int &idx, vector<int> &a) {
        if (!root || !ok) return;

        if (idx >= a.size() || root->val != a[idx]) {
            ok = false;
            return;
        }

        idx++;

        
        if (root->left && idx < a.size() && root->left->val != a[idx]) {
            ans.push_back(root->val);
            f(root->right, idx, a);
            f(root->left, idx, a);
        } else {
            f(root->left, idx, a);
            f(root->right, idx, a);
        }
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int idx = 0;
        f(root, idx, voyage);
        if (!ok) return {-1};
        return ans;
    }
};
