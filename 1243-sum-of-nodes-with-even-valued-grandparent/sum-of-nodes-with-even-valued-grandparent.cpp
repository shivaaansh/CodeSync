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
    int f(TreeNode* root, int par, int gpar) {
        if(root == NULL) {
            return 0;
        }
        int bit = root->val % 2;
        int sum = 0;
        sum += f(root->left, bit, par);
        sum += f(root->right, bit, par);
        if(gpar == 0) {
            sum += root->val;
        }
        return sum;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return f(root, 1, 1);
    }
};