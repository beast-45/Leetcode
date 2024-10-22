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
    long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long, vector<long>, greater<long>> pq; //Min Heap

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int n    = que.size();
            long levelSum = 0;
            while (n--) {
                TreeNode* poppedNode = que.front();
                que.pop();
                levelSum += poppedNode->val;
                if (poppedNode->left != NULL) {
                    que.push(poppedNode->left);
                }
                if (poppedNode->right != NULL) {
                    que.push(poppedNode->right);
                }
            }

            pq.push(levelSum);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.size() < k ? -1 : pq.top();
    }
};