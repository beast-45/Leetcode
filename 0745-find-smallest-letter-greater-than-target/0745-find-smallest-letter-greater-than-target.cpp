class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int i = 0;
        int j = n-1;

        while(i<=j){
            int mid = i + (j - i) / 2;
            if(letters[mid] > target){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return letters[i%n];
        
    }
};