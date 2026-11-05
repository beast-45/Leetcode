class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m = arr1.size() , n = arr2.size() , dist = 0;
        for(int i=0 ; i<m ; i++){
            bool present = false;
            for(int j=0 ; j<n ; j++){
                if(abs(arr1[i]-arr2[j]) <= d){
                    present = true;
                    break;
                };
            }
            if(!present) dist += 1;
        }
        return dist;
    }
};