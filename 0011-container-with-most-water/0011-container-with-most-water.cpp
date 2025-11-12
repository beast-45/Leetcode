class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 , j = height.size()-1;
        int water = 0 , maxWater = 0;
        while(i<j){
            water = min(height[i] , height[j])*(j-i);
            maxWater = max(maxWater,water);
            if(height[i] > height[j]){
                j--;
            }else if(height[j] > height [i]){
                i++;
            }else{
                j--;
            }
        }
        return maxWater;
    }
};