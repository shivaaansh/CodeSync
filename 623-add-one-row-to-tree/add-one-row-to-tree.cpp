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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> q;
        q.push(root);
        int len = 1;
        while(!q.empty() && len < depth - 1){
            int siz = q.size();
            for(int i =0 ; i<siz; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }              
            }len++;
        }
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            TreeNode* leftChild = new TreeNode(val);
            leftChild->left = node->left;
            node->left = leftChild;

            TreeNode* rightChild = new TreeNode(val);
            rightChild->right = node->right;
            node->right = rightChild;
        }return root;
    }
};