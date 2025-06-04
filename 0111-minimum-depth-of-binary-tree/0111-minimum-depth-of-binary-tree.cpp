class Solution {
public:
    int bfs(TreeNode* root){
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            auto [node,depth] = q.front();
            q.pop();
            if(!node->left && !node->right) return depth;
            if(node->left) q.push({node->left,depth+1});
            if(node->right) q.push({node->right,depth+1});
        }
        return -1;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return bfs(root);
    }
};