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
    int getLeftHeight(TreeNode* root)
    {
        TreeNode* temp = root;
        int lh = 0;
        while(temp)
        {
            temp = temp->left;
            lh += 1;
        }
        return lh;
    }
    int getRightHeight(TreeNode * root)
    {
        TreeNode* temp = root;
        int rh = 0;
        while(temp)
        {
            temp = temp->right;
            rh += 1;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);
        
        if(lh == rh) return ((pow(2,lh)-1));

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};