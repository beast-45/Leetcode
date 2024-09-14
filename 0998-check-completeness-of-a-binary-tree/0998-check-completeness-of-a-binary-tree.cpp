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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        bool past = false;

        while(!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            if(node == NULL) past = true;
            else
            {
                if(past == true) return false;
            que.push(node->left);
            que.push(node->right);
            }
        }
        return true;
    }
};