class WordDictionary {
public:
    struct trieNode{
        bool wordEnd;
        trieNode* child[26];
    };
    trieNode* makeTrieNode(){
        trieNode* nNode = new trieNode;
        nNode->wordEnd = false;
        for(int i=0 ; i<26 ; i++){
            nNode->child[i] = NULL;
        }
        return nNode;
    }
    trieNode* root;
    void insert(trieNode* root , string &word){
        trieNode* crawler = root;
        for(char &ch : word){
            if(!crawler->child[ch-'a']){
                crawler->child[ch-'a'] = makeTrieNode();
            }
            crawler = crawler->child[ch-'a'];
        }
        crawler->wordEnd = true;
    }
    bool searchWord(int index , trieNode* root , string &word){
        if(index == word.length()) return root->wordEnd;
        char ch = word[index];
        if(ch == '.'){
            for(int i=0 ; i<26 ; i++){
                if(root->child[i] && searchWord(index+1,root->child[i],word)){
                    return true;
                }
            }
            return false;
        }else{
            if(root->child[ch-'a'] == NULL) return false;
            return searchWord(index+1,root->child[ch-'a'],word);
        }
        return false;
    }
    WordDictionary() {
        root = makeTrieNode();
    }
    
    void addWord(string word) {
        insert(root,word);
    }
    
    bool search(string word) {
        return searchWord(0,root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */