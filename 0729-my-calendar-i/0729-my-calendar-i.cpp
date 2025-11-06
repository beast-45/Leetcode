class MyCalendar {
public:
    map<int,int> mp;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto next = mp.lower_bound(startTime);
        if(next != mp.end() && next->first < endTime) return false;
        if(next != mp.begin()){
            auto prevBooking = prev(next);
            if(prevBooking->second > startTime) return false;
        }
        mp[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */