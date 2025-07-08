class Solution {
public:
    int m,n;
    vector<pair<int,int>> directions {{1,0},{-1,0},{0,-1},{0,1}};
    vector<string> result;
    struct trieNode{
        bool endOfWord;
        string word;
        trieNode* children[26];
    };
    trieNode* makeTrieNode(){
        trieNode* nNode = new trieNode();
        nNode->endOfWord = false;
        nNode->word = "";
        for(int i=0 ; i<26 ; i++){
            nNode->children[i] = NULL;
        }
        return nNode;
    }
    void insert(trieNode* root , string &word){
        trieNode* crawler = root;
        for(int i=0 ; i<word.length() ; i++){
            char ch = word[i];
            if(crawler->children[ch-'a'] == NULL){
                crawler->children[ch-'a'] = makeTrieNode();
            }
            crawler = crawler->children[ch-'a'];
        }
        crawler->endOfWord = true;
        crawler->word = word;
    }
    void findWord(int i , int j , trieNode* root , vector<vector<char>> &board){
        if(i<0 || i>=m || j<0 || j>=n) return;
        if(board[i][j] == '$' || root->children[board[i][j]-'a'] == NULL) return;
        root = root->children[board[i][j]-'a'];
        if(root->endOfWord){
            result.push_back(root->word);
            root->endOfWord = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &[di,dj] : directions){
            int ni = i + di , nj = j + dj;
            findWord(ni,nj,root,board);
        }
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size() , n = board[0].size();
        trieNode* root = makeTrieNode();
        for(string &word : words){
            insert(root,word);
        }
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                char ch = board[i][j];
                if(root->children[ch-'a'] != NULL){
                    findWord(i,j,root,board);
                }
            }
        }
        return result;
    }
};