class Solution {
public:
    int swapNum(vector<int>& vec) {
        int swaps = 0;
        vector<int> sorted(begin(vec), end(vec));
        sort(begin(sorted), end(sorted));
        unordered_map<int, int> mp;

        for(int i = 0; i < vec.size(); i++)
        {
            mp[vec[i]] = i;
        }

        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == sorted[i]) continue; 

            int currIdx = mp[sorted[i]];
            mp[vec[i]] = currIdx;
            mp[vec[currIdx]] = i;
            swap(vec[currIdx], vec[i]);
            swaps++;
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int result = 0;

        while(!que.empty()) {
            int n = que.size(); 
            vector<int> vec;

            while(n--) {
                TreeNode* temp = que.front();
                que.pop();
                vec.push_back(temp->val);
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            result += swapNum(vec);
        }

        return result;
    }
};
