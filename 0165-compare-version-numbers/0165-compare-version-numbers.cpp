class Solution {
public:
    vector<string> getRevisions(string &v){
        vector<string> revisions;
        stringstream ss(v);
        string revision = "";
        while(getline(ss,revision,'.')){
            revisions.push_back(revision);
        }
        return revisions;
    }
    int compareVersion(string version1, string version2) {
        vector<string> v1,v2;
        v1 = getRevisions(version1);
        v2 = getRevisions(version2);
        int n1 = v1.size() , n2 = v2.size();
        int i = 0 , longer = max(n1,n2);
        while(i<longer){
            int a = i<n1 ? stoi(v1[i]) : 0;
            int b = i<n2 ? stoi(v2[i]) : 0;
            if(a<b) return -1;
            else if(a>b) return 1;
            else i++;
        }
        return 0;
    }
};