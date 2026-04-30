class Robot {
public:
    
    vector<vector<int>> pos;
    vector<string> directions{"East","North","West","South"};
    int index = 0;
    bool moved = false;
    Robot(int width, int height) {
        for(int i=0 ; i<width ; i++){
            pos.push_back({i,0,0});  //East
        }
        for(int j=1 ; j<height ; j++){
            pos.push_back({width-1,j,1});  //North
        }
        for(int i=width-2 ; i>=0 ; i--){
            pos.push_back({i,height-1,2});   //West
        }
        for(int j=height-2 ; j>0 ; j--){ 
            pos.push_back({0,j,3});    //South  //0,0 already filled
        }  
        pos[0][2] = 3;   //Making South because if moved, then it will always face S at {0,0}
    }
    
    void step(int num) {
        moved = true;
        index = (index+num)%pos.size();
    }
    
    vector<int> getPos() {
        return {pos[index][0],pos[index][1]};
    }
    
    string getDir() {
        if(!moved) return "East";
        return directions[pos[index][2]];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */