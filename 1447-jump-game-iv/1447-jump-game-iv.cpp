class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(); 

        unordered_map<int,vector<int>> mp;
        vector<bool> visited(n,false);

        for(int i=0 ; i<n ; i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> que;
        que.push(0);
        visited[0] = true;

        int jumps = 0;

        while(!que.empty()){
            int size = que.size();
            while(size--){
                int temp = que.front();
                que.pop();

                int moveBackward = temp - 1;
                int moveForward = temp + 1;

                if(temp == n-1){
                    return jumps;
                }

                if(moveBackward >= 0 && visited[moveBackward] == false){
                    que.push(moveBackward);
                    visited[moveBackward] = true;
                }
                if(moveForward < n && visited[moveForward] == false){
                    que.push(moveForward);
                    visited[moveForward] = true;
                }

                for(int &index : mp[arr[temp]]){
                    if(!visited[index]){
                        que.push(index);
                        visited[index] = true;
                    }
                }
                mp.erase(arr[temp]);
            }
            jumps += 1;
        }
        return -1;
    }
};