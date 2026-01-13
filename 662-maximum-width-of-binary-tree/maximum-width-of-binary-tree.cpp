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
    #define ll long long
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0LL});
        ll maxi = 1;
        while(!q.empty()) {
            int size = q.size();
            ll mini = q.front().second, f = 0, s = 0;
            for(int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                
                q.pop();
                idx = idx - mini;
                if(i == 0) {
                    f = idx;
                }
                if(node->left) {
                    q.push({node->left, 2LL*idx+1LL});
                }
                if(node->right) {
                    q.push({node->right, 2LL*idx+2LL});
                }
                s = idx;
            }
            maxi = max(maxi, s - f + 1LL);
        }
        return maxi;
    }
};