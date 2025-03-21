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
    int swaps(vector<int> &vec){
        int n = vec.size();
        int op = 0;
        vector<int> sortedVec(begin(vec),end(vec));
        sort(begin(sortedVec),end(sortedVec));
        unordered_map<int,int> mp;
        for(int i=0 ; i<n ; i++){
            mp[vec[i]] = i;
        }
        for(int i=0 ; i<n ; i++){
            if(vec[i] != sortedVec[i]){
                int index = mp[sortedVec[i]];
                mp[sortedVec[i]] = i;
                mp[vec[i]] = index; 
                swap(vec[i],vec[index]);
                op += 1;
            }
        }
        return op;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int operations = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            operations += swaps(level);
        }
        return operations; 
    }
};