class Trie {
public:
    struct trieNode{
        bool wordEnd;
        string word;
        trieNode* child[26];
    };
    trieNode* root;
    trieNode* makeTrieNode(){
        trieNode* newNode = new trieNode;
        newNode->wordEnd = false;
        newNode->word = "";
        for(int i=0 ; i<26 ; i++){
            newNode->child[i] = NULL;
        }
        return newNode;
    }
    Trie(){
        root = makeTrieNode();
    }
    void insert(string word) {
        trieNode* crawler = root;
        for(char &ch : word){
            if(crawler->child[ch-'a'] == NULL){
                crawler->child[ch-'a'] = makeTrieNode();
            }
            crawler = crawler->child[ch-'a'];
        }
        crawler->wordEnd = true;
        crawler->word = word;
    }
    
    bool search(string word) {
        trieNode* crawler = root;
        for(char &ch : word){
            if(crawler->child[ch-'a'] == NULL) return false;
            else crawler = crawler->child[ch-'a'];
        }
        if(crawler->wordEnd == true && crawler->word == word) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;
        int i;
        for(i=0 ; i<prefix.length() ; i++){
            if(crawler->child[prefix[i]-'a'] == NULL) return false;
            else crawler = crawler->child[prefix[i]-'a'];
        }
        if(i == prefix.length()) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */