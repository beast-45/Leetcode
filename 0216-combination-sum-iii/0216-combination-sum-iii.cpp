class Solution {
public:
    void solve(int num , int sum , int k , int n , vector<int> &temp , vector<vector<int>> &result){
        if(sum == n && temp.size() == k){
            result.push_back(temp);
            return;
        }
        if(sum > n || num > 9 || temp.size() > k) return;
        temp.push_back(num);
        solve(num+1,sum+num,k,n,temp,result);
        temp.pop_back();
        solve(num+1,sum,k,n,temp,result);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(1,0,k,n,temp,result);
        return result;
    }
};