class WordDictionary {
public:
    /** Initialize your data structure here. */
    map<int,vector<string>> v;
    
    void addWord(string word) {
      v[word.size()].push_back(word);
    }

    bool search(string word) {
        bool ans=true;
        vector<string> p=v[word.size()];
        for(int i=0;i<p.size();i++)
        {   int k=0;
            ans=1;
            for(int j=0;j<p[i].size();j++)
            {
                if(word[k]==p[i][j]||word[k]=='.')
                {
                    k++;
                }
                else
                {
                    ans=false;
                    break;
                }
            }
         if(ans&&k==word.size())
         {
             return true;
         }
         else
             ans=false;    
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */