class EventManager {
public:
    typedef pair<int,int> P;
    unordered_map<int,int> eventToPriMap;
    priority_queue<P,vector<P>> pq;
    EventManager(vector<vector<int>>& events) {
        for(auto &event : events){
            eventToPriMap[event[0]] = event[1];
            pq.push({event[1],-event[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        eventToPriMap[eventId] = newPriority;
        pq.push({newPriority,-eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto[pri,negId] = pq.top();
            pq.pop();
            int id = -negId;
            if(eventToPriMap.find(id) != eventToPriMap.end() && eventToPriMap[id] == pri){
                eventToPriMap.erase(id);
                return id;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */