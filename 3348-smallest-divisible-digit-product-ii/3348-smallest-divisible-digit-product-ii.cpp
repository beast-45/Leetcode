class Solution {
public:
    using ll = long long;
    string getRN(ll required, int length){
        string str;
        for(int digit=9 ; digit>=2 ; digit--){
            while(required % digit == 0){
                str.push_back(digit + '0');
                required /= digit;
            }
        }
        while((int)str.length() < length){
            str.push_back('1');
        }
        reverse(begin(str),end(str));
        return str;
    }

    string smallestNumber(string num, long long t) {
        int n = num.length();
        ll temp = t;
        for(int primeFact : {2,3,5,7}){
            while(temp % primeFact == 0){
                temp /= primeFact;
            }
        }
        if(temp != 1) return "-1";

        vector<ll> remainingFactor(n+1,t);
        for(int i=0 ; i<n ; i++){
            int digit = num[i]-'0';
            if(digit == 0) break;
            remainingFactor[i+1] = remainingFactor[i]/gcd(remainingFactor[i],(ll)digit);
        }

        if(remainingFactor[n] == 1) return num;

        int zeroPos = num.find('0');
        int zeroIndex = n-1;
        if(zeroPos != -1){
            zeroIndex = zeroPos;
        }

        for(int i=zeroIndex ; i>=0 ; i--){
            ll required = remainingFactor[i];
            int freeSlots = n-1-i;

            for(int dig=(num[i]-'0')+1 ; dig<=9 ; dig++){
                ll furtherRequired = required/gcd(required,(ll)dig);
                string requiredNumber = getRN(furtherRequired,freeSlots);
                if((int)requiredNumber.length() == freeSlots){
                    return num.substr(0,i) + char(dig + '0') + requiredNumber;
                }
            }
        }
        return getRN(t,n+1);
    }
};