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
    bool solve(TreeNode* root , int sum , int target){
        if(!root) return false;
        sum += root->val;
        if(!root->left && !root->right && sum == target){
            return true;
        } 
        bool L = solve(root->left,sum,target);
        bool R = solve(root->right,sum,target);
        return L || R;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,0,targetSum);
    }
};