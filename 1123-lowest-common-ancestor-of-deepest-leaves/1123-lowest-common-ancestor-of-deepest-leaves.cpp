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
    unordered_map<int,int> mp;
    int maxD = 0;
    void fillDepth(TreeNode* root , int currDepth){
        if(!root) return;
        maxD = max(maxD,currDepth);
        mp[root->val] = currDepth;
        fillDepth(root->left,currDepth+1);
        fillDepth(root->right,currDepth+1);
    }
    TreeNode* lowestCA(TreeNode* root){
        if(!root || mp[root->val] == maxD) return root;
        TreeNode* left = lowestCA(root->left);
        TreeNode* right = lowestCA(root->right);
        if(left && right) return root;
        return left != NULL ? left : right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        fillDepth(root,0);
        return lowestCA(root);
    }
};