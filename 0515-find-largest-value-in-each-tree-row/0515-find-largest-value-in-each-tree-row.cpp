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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            vector<int> lvl;
            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                lvl.push_back(temp->val);
            }
            int largestRowVal = *max_element(begin(lvl) , end(lvl));
            result.push_back(largestRowVal);
        }
        return result; 
    }
};