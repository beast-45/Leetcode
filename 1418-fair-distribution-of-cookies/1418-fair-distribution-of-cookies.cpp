class Solution {
public:
    void distribute(int index , vector<int> &child , vector<int> &cookies , int k , int &minUnfairness){
        if(index >= cookies.size()){
            int unfairness = *max_element(begin(child),end(child));
            minUnfairness = min(minUnfairness , unfairness);
            return;
        }
        int cookie = cookies[index];
        for(int i=0 ; i<k ; i++){
            child[i] += cookie;
            distribute(index+1 , child , cookies , k , minUnfairness);
            child[i] -= cookie;
            if(child[i] == 0){
                break;
            }
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int minUnfairness = INT_MAX;
        sort(cookies.rbegin(),cookies.rend());
        vector<int> child(k , 0);
        distribute(0 , child , cookies , k , minUnfairness);
        return minUnfairness;
    }
};