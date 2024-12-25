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
    bool isEvenOddTree(TreeNode* root) {
        if (root == NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
                level.push_back(temp->val);
            }
            int sz = level.size();
            if(lvl % 2 == 0)
            {
                for(int i=0 ; i<sz ; i++)
                {
                    if(level[i] % 2 == 0) return false;
                    if(i > 0 && level[i-1] >= level[i]) return false;
                }
            } 
            else
            {
                for(int i=0; i<sz ; i++)
                {
                    if(level[i] % 2 == 1) return false;
                    if(i > 0 && level[i-1] <= level[i]) return false;
                }
            }
            lvl++;
        }
        return true;
    }
};