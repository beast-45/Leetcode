class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n =  people.size();
        sort(begin(people) , end(people));
        
        int nBoats = 0;
        int i=0 ; 
        int j=n-1;

        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
                j--;
                nBoats += 1;
            }
            else
            {
                j--;
                nBoats += 1;
            }
        }
        return nBoats;
        
    }
};