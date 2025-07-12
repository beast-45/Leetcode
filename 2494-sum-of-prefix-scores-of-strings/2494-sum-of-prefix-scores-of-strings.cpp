class Solution {
public:
    struct trieNode{
        int count;
        trieNode* child[26];
    };
    trieNode* makeTrieNode(){
        trieNode* nNode = new trieNode;
        nNode->count = 0;
        for(int i=0 ; i<26 ; i++){
            nNode->child[i] = nullptr;
        }
        return nNode;
    }
    void insert(trieNode* root , string &word){
        trieNode* crawler = root;
        for(char &ch : word){
            if(!crawler->child[ch-'a']){
                crawler->child[ch-'a'] = makeTrieNode();
            }
            crawler->child[ch-'a']->count += 1;
            crawler = crawler->child[ch-'a'];
        }
    }
    int getPrefixScore(trieNode* root , string &word){
        int score = 0;
        trieNode* crawler = root;
        for(char &ch : word){
            crawler = crawler->child[ch-'a'];
            score += crawler->count;
        }
        return score;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        trieNode* root = makeTrieNode();
        for(string word : words){
            insert(root,word);
        }
        vector<int> result(n);
        for(int i=0 ; i<n ; i++){
            result[i] = getPrefixScore(root,words[i]);
        }
        return result;
    }
};