class Solution {
public:
    void solve(int num , int n , int k , vector<int> &temp , vector<vector<int>> &result){
        if(temp.size() == k){
            result.push_back(temp);
            return;
        }
        if(num > n){
            return;
        }
        temp.push_back(num);
        solve(num+1,n,k,temp,result);
        temp.pop_back();
        solve(num+1,n,k,temp,result);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(1,n,k,temp,result);
        return result;
    }
};