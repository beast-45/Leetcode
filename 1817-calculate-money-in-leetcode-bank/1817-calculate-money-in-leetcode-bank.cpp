class Solution {
public:
    int totalMoney(int n) {
        int money = 0;
        int weeks = n/7;
        int week = 0 , days = 0;
        while(week<=weeks){
            for(int i=1 ; i<=7 && days < n ; i++){
                money += (i+week);
                days++;
            }
            week++;
        }
        return money;  
    }
};