class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int index = 0;
        int count = 0;
        vector<int> result(n);
        for(int &num : nums){
            if(num < pivot){
                result[index] = num;
                index += 1;
            }
            else if(num == pivot){
                count += 1;
            }
        }
        for(int j=0 ; j<count ; j++){
            result[index] = pivot;
            index += 1;
        }
        for(int &num : nums){
            if(num > pivot){
                result[index] = num;
                index += 1;
            }
        }
        return result;
    }
};