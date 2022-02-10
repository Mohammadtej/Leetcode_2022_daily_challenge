class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        
        int n = num;
        while(s.size() != 1)
        {
            n = 0;
            
            for(char x : s)
                n += (x - '0');
            s = to_string(n);
        }
        
        return n;
    }
};