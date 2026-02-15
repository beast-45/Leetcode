class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> tlb(100,false);
        for(int &bulb : bulbs){
            if(tlb[bulb] == false) tlb[bulb] = true;
            else tlb[bulb] = false;
        }
        vector<int> on;
        for(int i=0 ; i<=100 ; i++){
            if(tlb[i]) on.push_back(i);
        }
        return on;
    }
};