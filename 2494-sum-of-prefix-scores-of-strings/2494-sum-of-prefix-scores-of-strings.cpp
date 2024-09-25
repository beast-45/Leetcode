struct trieNode
{
    int countP = 0;
    trieNode* children[26];
};
class Solution {
public:
    trieNode * getTrieNode()
    {
        trieNode * newnode = new trieNode();
        for(int i=0 ; i<26 ; i++)
        {
            newnode->children[i] = nullptr;
        }
        newnode->countP = 0 ;
        return newnode;
    }
    void insert(string & word , trieNode* root)
    {
        trieNode * crawl = root;
        for(char & ch : word)
        {
            int idx = ch-'a';
            if(!crawl->children[idx])
            {
                crawl->children[idx]=getTrieNode();
            }
            crawl->children[idx]->countP+=1;
            crawl = crawl->children[idx];
        }
    }
    int getScore(string &word , trieNode*root)
    {
        trieNode* crawl = root;
        int score = 0;
        for(char&ch : word)
        {
            int idx = ch-'a';
            score += crawl->children[idx]->countP;
            crawl = crawl->children[idx];
        }
        return score;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        trieNode * root = getTrieNode();
        for(string & word : words)
        {
            insert(word , root);
        }
        vector<int> result(n);
        for(int i=0 ; i<n ; i++)
        {
            result[i] = getScore(words[i] , root);
        }
        return result;
    }
};