class Trie {
public:
    struct TrieNode{
        bool wordEnd;
        string word;
        TrieNode* child[26];
    };

    TrieNode* makeTrieNode(){
        TrieNode* nNode = new TrieNode();
        nNode->wordEnd = false;
        nNode->word = "";
        for(int i=0 ; i<26 ; i++){
            nNode->child[i] = nullptr;
        }
        return nNode;
    }

    TrieNode* root;

    Trie() {
        root = makeTrieNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;
        for(char &ch : word){
            if(!crawler->child[ch-'a']){
                crawler->child[ch-'a'] = makeTrieNode();
            }
            crawler = crawler->child[ch-'a'];
        }
        crawler->wordEnd = true;
        crawler->word = word;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;
        for(char &ch : word){
            if(!crawler->child[ch-'a']) return false;
            crawler = crawler->child[ch-'a'];
        }
        return crawler->wordEnd == true && crawler->word == word ? true : false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        int i = 0;
        for(char &ch : prefix){
            if(!crawler->child[ch-'a']) return false;
            crawler = crawler->child[ch-'a'];
            i++;
        }
        return i == prefix.length() ? true : false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */