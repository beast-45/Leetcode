class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty())
        {
            TreeNode* n1 = q1.front();
            q1.pop();
            TreeNode* n2 = q2.front();
            q2.pop();

            if(n1->val != n2->val) return false;

            if(n1->left != NULL && n2->left != NULL)
            {
                q1.push(n1->left);
                q2.push(n2->left);
            }
            else if(n1->left != NULL || n2->left != NULL) return false;
            if(n1->right != NULL && n2->right != NULL)
            {
                q1.push(n1->right);
                q2.push(n2->right);
            }
            else if(n1->right != NULL || n2->right != NULL) return  false;
        }
        return true;
        
    }
};