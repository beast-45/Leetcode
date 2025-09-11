class Solution {
public:
    struct trieNode{
        bool wordEnd;
        string word;
        trieNode* child[26];
    };
    trieNode* makeTrieNode(){
        trieNode* nNode = new trieNode;
        nNode->wordEnd = false;
        nNode->word = "";
        for(int i=0 ; i<26 ; i++){
            nNode->child[i] = NULL;
        }
        return nNode;
    }
    void insert(trieNode* root , string &word){
        trieNode* crawler = root;
        for(char &ch : word){
            if(!crawler->child[ch-'a']){
                crawler->child[ch-'a'] = makeTrieNode();
            }
            crawler = crawler->child[ch-'a'];
        }
        crawler->wordEnd = true;
        crawler->word = word;
    }
    string searchPrefix(trieNode* root , string &word){
        trieNode* crawler = root;
        int i;
        for(i=0 ; i<word.size() ; i++){
            char ch = word[i];
            if(!crawler->child[ch-'a']) return "";
            else crawler = crawler->child[ch-'a'];
            if(crawler->wordEnd == true){
                return crawler->word;
            } 
        }
        return "";
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        string result;
        trieNode* root = makeTrieNode();
        for(auto &word : dictionary){
            insert(root,word);
        }
        int n = sentence.length();
        for(int i=0 ; i<n ; i++){
            string word = "";
            while(i<n && sentence[i] != ' '){
                word += sentence[i];
                i++;
            }
            string rootFound = searchPrefix(root,word);
            result += rootFound == "" ? word + " " : rootFound + " ";
        }
        result.pop_back();
        return result;
    }
};