/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        if(o == NULL) return NULL;
        if(o == t) {
            return c;
        }
        TreeNode* left = getTargetCopy(o->left, c->left, t);
        TreeNode* right = getTargetCopy(o->right, c->right, t);
        if(left == NULL && right == NULL) {
            return NULL;
        }
        else if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        return NULL;
    }
};