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
    void makeAdj(TreeNode* root , int parent , unordered_map<int,vector<int>> &adj){
        if(!root){
            return;
        }
        if(parent != -1){
            adj[root->val].push_back(parent);
            adj[parent].push_back(root->val);
        }
        if(root->left){
            makeAdj(root->left,root->val,adj);
        }
        if(root->right){
            makeAdj(root->right,root->val,adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;
        makeAdj(root,-1,adj);
        queue<int> q;
        unordered_set<int> vis;
        int time = 0;
        q.push(start);
        vis.insert(start);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int u = q.front();
                q.pop();
                for(int &v : adj[u]){
                    if(!vis.count(v)){
                        q.push(v);
                        vis.insert(v);
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};