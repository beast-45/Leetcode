class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool notPresent = false;
        if(mp.find(val) == mp.end()){
            notPresent = true;
            nums.push_back(val);
            int n = nums.size();
            mp[val] = n-1;
        }
        return notPresent;
    }
    
    bool remove(int val) {
        bool found = false;
        if(mp.find(val) != mp.end()){
            found = true;
            int index = mp[val];
            int lastElement = nums.back();
            nums[index] = lastElement;
            mp[lastElement] = index;
            nums.pop_back();
            mp.erase(val);
        }
        return found;
    }
    
    int getRandom() {
        int n = nums.size();
        int index = rand()%n;
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */