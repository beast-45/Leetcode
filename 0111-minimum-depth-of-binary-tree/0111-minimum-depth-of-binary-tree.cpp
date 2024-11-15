class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(root->left == NULL && root->right == NULL) return 1;

        int L;
        int R;

        if(root->left != NULL)
        {
            L = minDepth(root->left);
        }
        else L = INT_MAX;

        if(root->right != NULL)
        {
            R = minDepth(root->right);
        }
        else R = INT_MAX;

        return 1 + min(L,R);
    }
};