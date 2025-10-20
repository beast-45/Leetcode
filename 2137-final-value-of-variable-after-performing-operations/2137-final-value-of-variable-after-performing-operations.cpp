class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int finalVal = 0;
        for(auto &op : operations){
            if(op[1] == '+') finalVal++;
            else finalVal--;
        }
        return finalVal;
    }
};