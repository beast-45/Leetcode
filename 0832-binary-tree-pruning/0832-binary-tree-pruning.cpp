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
    bool isOnePresent(TreeNode* node)
    {
        if(node == NULL) return false;
        if(node->val == 1) return true;
        return isOnePresent(node->left) || isOnePresent(node->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return NULL;

        if(!isOnePresent(root->left)) root->left = NULL;
        if(!isOnePresent(root->right)) root->right = NULL;

        pruneTree(root->left);
        pruneTree(root->right);

        if(root->left == NULL && root->right == NULL && root->val == 0) return NULL;
        return root; 
    }
};