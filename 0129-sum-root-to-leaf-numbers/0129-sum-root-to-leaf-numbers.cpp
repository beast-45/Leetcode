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
    int solve(TreeNode* root , int currVal)
    {
        if(!root) return 0;
        currVal = (currVal*10) + root->val;
        if(root->left == NULL && root->right == NULL) return currVal;

        int lval = solve(root->left , currVal);
        int rval = solve(root->right , currVal);

        return lval + rval;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root , 0);  
    }
};