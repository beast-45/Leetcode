class Solution {
public:
    struct trieNode{
        trieNode* left;
        trieNode* right;
    };
    trieNode* makeTrieNode(){
        trieNode* nNode = new trieNode;
        nNode->left = nullptr;
        nNode->right = nullptr;
        return nNode;
    }
    void insert(trieNode* root , int num){
        trieNode* crawler = root;
        for(int i=31 ; i>=0 ; i--){
            int iBit = (num>>i)&1;
            if(iBit == 0){
                if(!crawler->left){
                    crawler->left = makeTrieNode();
                }
                crawler = crawler->left;
            }else{
                if(!crawler->right){
                    crawler->right = makeTrieNode();
                }
                crawler = crawler->right;
            }
        }
    }
    int findMaxXor(trieNode* root , int num){
        int x = 0;
        trieNode* crawler = root;
        for(int i=31 ; i>=0 ; i--){
            int iBit = (num>>i)&1;
            if(iBit == 0){
                if(crawler->right != nullptr){
                    x += pow(2,i);
                    crawler = crawler->right;
                }else{
                    crawler = crawler->left;
                }
            }else{
                if(crawler->left != nullptr){
                    x += pow(2,i);
                    crawler = crawler->left;
                }else{
                    crawler = crawler->right;
                }
            }
        }
        return x;
    }
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = makeTrieNode();
        for(int num : nums){
            insert(root,num);
        }
        int maxXor = 0;
        for(int num : nums){
            int currXOR = findMaxXor(root,num);
            maxXor = max(maxXor,currXOR);
        }
        return maxXor;
    }
};