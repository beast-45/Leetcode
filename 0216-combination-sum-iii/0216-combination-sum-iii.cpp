class Solution {
public:
    void solve(int num , int sum , vector<int> &temp , vector<vector<int>> &result , int k , int n){
        if(temp.size() > k || sum > n){
            return;
        }
        if(temp.size() == k && sum == n){
            result.push_back(temp);
            return;
        }
        if(num > 9){
            return;
        }
        temp.push_back(num);
        solve(num+1,sum+num,temp,result,k,n);
        temp.pop_back();
        solve(num+1,sum,temp,result,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(1,0,temp,result,k,n);
        return result;
    }
};