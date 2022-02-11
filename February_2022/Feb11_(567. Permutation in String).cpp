class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int window_sz = s1.size();
        
        if(s2.size() < window_sz)
            return 0;
        
        int freq_s1[26], freq_s2[26];
        
        memset(freq_s1, 0, sizeof(freq_s1));
        memset(freq_s2, 0, sizeof(freq_s2));
        
        
        for(int i=0; i<window_sz; i++)
            freq_s1[s1[i] - 'a']++, freq_s2[s2[i] - 'a']++;
        
        bool is_equal = true;
        for(int i=0; i<26; i++)
        {
            if(freq_s1[i] != freq_s2[i])
            {
                is_equal = false;
                break;
            }
        }
        
        
        if(is_equal == 1)
            return 1;
        
        for(int i=window_sz; i<s2.size(); i++)
        {
            freq_s2[s2[i - window_sz] - 'a']--;
            freq_s2[s2[i] - 'a']++;
            
            is_equal = true;
            for(int i=0; i<26; i++)
            {
                if(freq_s1[i] != freq_s2[i])
                {
                    is_equal = false;
                    break;
                }
            }


            if(is_equal == 1)
                return 1;
        }
        
        return 0;
    }
};