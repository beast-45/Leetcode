class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> result;

        result.push_back(folder[0]); 

        for(int i = 1; i < folder.size(); i++) {

            string currFolder = folder[i];
            string lastFolder = result.back();
            lastFolder += '/';

            if(currFolder.find(lastFolder) != 0) {
                result.push_back(currFolder);
            }
        }

        return result;

    }
};
