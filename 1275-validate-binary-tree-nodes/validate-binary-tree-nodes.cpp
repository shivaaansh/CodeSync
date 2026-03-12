class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& leftChild, vector<int>& rightChild) {
        if(vis[node]) return false;

        vis[node] = 1;

        if(leftChild[node] != -1) {
            if(!dfs(leftChild[node], vis, leftChild, rightChild))
                return false;
        }

        if(rightChild[node] != -1) {
            if(!dfs(rightChild[node], vis, leftChild, rightChild))
                return false;
        }

        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){
            if(leftChild[i] != -1 && ++indegree[leftChild[i]] > 1)
                return false;

            if(rightChild[i] != -1 && ++indegree[rightChild[i]] > 1)
                return false;
        }

        int root = -1;

        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                if(root != -1) return false;
                root = i;
            }
        }

        if(root == -1) return false;

        vector<int> vis(n,0);

        if(!dfs(root, vis, leftChild, rightChild))
            return false;

        for(int v : vis)
            if(v == 0) return false;

        return true;
    }
};