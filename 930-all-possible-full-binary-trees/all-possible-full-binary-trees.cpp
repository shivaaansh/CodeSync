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
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0 ) {
            return {};
        }
        if(n == 1) {
            return {new TreeNode(0)};
        }
        vector<TreeNode*> ans;
        for(int lc = 1; lc < n; lc+=2) {
            auto lt = allPossibleFBT(lc);
            auto rt = allPossibleFBT(n - lc - 1);
            for(auto l : lt) {
                for(auto r : rt) {
                    TreeNode* t = new TreeNode(0);
                    t->left = l;
                    t->right = r; 
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};