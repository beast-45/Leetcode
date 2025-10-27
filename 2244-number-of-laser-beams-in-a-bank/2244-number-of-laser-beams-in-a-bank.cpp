class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int lasers = 0 , devicesOnPrevFloor = 0;
        for(auto &floor : bank){
            int devices = count(begin(floor),end(floor),'1');
            if(devices){
                lasers += (devices*devicesOnPrevFloor);
                devicesOnPrevFloor = devices;
            }
        }
        return lasers;
    }
};