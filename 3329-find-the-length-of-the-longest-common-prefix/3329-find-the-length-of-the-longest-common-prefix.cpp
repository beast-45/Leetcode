class Solution {
public:
    struct trieNode{
        trieNode* child[10];
    };
    trieNode* makeTrieNode(){
        trieNode* nNode = new trieNode;
        for(int i=0 ; i<10 ; i++){
            nNode->child[i] = nullptr;
        }
        return nNode;
    }
    void insert(trieNode* root , int num){
        string word = to_string(num);
        trieNode* crawler = root;
        for(char &ch : word){
            if(!crawler->child[ch-'0']){
                crawler->child[ch-'0'] = makeTrieNode();
            }
            crawler = crawler->child[ch-'0'];
        }
    }
    int search(trieNode* root , int num){
        string word = to_string(num);
        trieNode* crawler = root;
        int length = 0;
        for(char &ch : word){
            if(crawler->child[ch-'0']){
                length += 1;
                crawler = crawler->child[ch-'0'];
            }else{
                break;
            }
        }
        return length;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trieNode* root = makeTrieNode();
        for(int num : arr1){
            insert(root,num);
        }
        int maxLen = 0;
        for(int num : arr2){
            int len = search(root,num);
            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};