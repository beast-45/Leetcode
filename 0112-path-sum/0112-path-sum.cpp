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
    bool solve(TreeNode* root , int sum , int &targetSum)
    {
        if(root == NULL) return false;
        sum += root->val;
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == targetSum) return true;
            return false;
        }
        bool L = solve(root->left , sum , targetSum);
        bool R = solve(root->right , sum , targetSum);

        return L || R ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return solve(root , sum , targetSum);
        
    }
};