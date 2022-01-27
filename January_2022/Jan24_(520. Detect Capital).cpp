class Solution {
public:
    bool detectCapitalUse(string word) {
        int caps = 0;
        
        for(char x : word)
        {
            if(isupper(x))
                caps++;
        }
        
        if(caps == 0)
            return 1;
        if(caps == word.size())
            return 1;
        if(caps == 1 && isupper(word[0]))
            return 1;
        return 0;
    }
};