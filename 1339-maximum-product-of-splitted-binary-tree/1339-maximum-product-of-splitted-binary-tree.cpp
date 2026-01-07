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
    int M = 1e9+7;
    int ts;
    long maxP = 0;
    int totalSum(TreeNode* root){
        if(!root) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }
    int find(TreeNode* root){
        if(!root) return 0;
        int ls = find(root->left);
        int rs = find(root->right);
        long subSum = root->val + ls + rs;
        long remSum = ts - subSum;
        maxP = max(maxP,subSum*remSum);
        return subSum;
    }
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        ts = totalSum(root);
        find(root);
        return maxP%M;
    }
};