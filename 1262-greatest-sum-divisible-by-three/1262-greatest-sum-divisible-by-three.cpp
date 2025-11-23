class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> r1 , r2;
        for(int &num : nums){
            sum += num;
            if(num % 3 == 1) r1.push_back(num);
            else if(num % 3 == 2) r2.push_back(num);
        }
        if(sum % 3 == 0) return sum;
        sort(begin(r1),end(r1));
        sort(begin(r2),end(r2));
        int result = 0;
        int rem = sum % 3;
        if(rem == 1){
            int remove1 = r1.size() >= 1 ? r1[0] : INT_MAX;
            int remove2 = r2.size() >= 2 ? (r2[0]+r2[1]) : INT_MAX;
            result = max(result,sum-min(remove1,remove2));
        }else{
            int remove1 = r2.size() >= 1 ? r2[0] : INT_MAX;
            int remove2 = r1.size() >= 2 ? (r1[0]+r1[1]) : INT_MAX;
            result = max(result,sum-min(remove1,remove2));
        }
        return result;
    }
};