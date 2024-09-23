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
    vector<vector<int>> result;
    void fill(TreeNode* root , int sum , vector<int> temp , int targetSum)
    {
        if(root == NULL) return;
        sum += root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == targetSum) result.push_back(temp);
        }
        fill(root->left , sum , temp , targetSum);
        fill(root->right , sum , temp , targetSum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        fill(root , sum , temp , targetSum);
        return result;
    }
};