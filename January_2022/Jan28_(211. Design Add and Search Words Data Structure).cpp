class WordDictionary {
public:
    
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
    struct node{
        char val;
        bool end;
        node *alpha[26];
        
        node(char x)
        {
            val = x;
            end = false;
            
            for(int i=0; i<26; i++)
                alpha[i] = NULL;
        }
    };
    
    node *root;
    WordDictionary() {
        root = new node('c');
    }
    
    void addWord(string word) {
        node *curr = root;
        
        for(char x : word)
        {
            if(curr->alpha[x-'a'] == NULL)
            {
                curr->alpha[x-'a'] = new node(x);
            }
            curr = curr->alpha[x-'a'];
        }
        
        curr->end = true;
    }
    // current stores the value at i
    
    bool rec(string str, int i, node *curr)
    {
        if(curr == NULL)
            return 0;
        if(i+1 == str.size())
            return curr->end;
        if(str[i+1] == '.')
        {
            bool f = false;
            
            for(int j=0; j<26; j++){
                f |= rec(str, i+1, curr->alpha[j]);
                
                if(f)
                    break;
            }
            return f;
        }
        

        return rec(str, i+1, curr->alpha[str[i+1] - 'a']);
    }
    bool search(string word) {
        return rec(word, -1, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */