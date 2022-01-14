class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        
        while(i < n && s[i] == ' ')
            i++;
        int sign = 1;
        
        if(s[i] == '-')
            sign = -1;
        if(s[i] == '+' || s[i] == '-')
            i++;
        long res = 0;
        
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            res = res * 10 + (s[i] - '0');
            if(res > INT_MAX)
                break;
            if(res < INT_MIN)
                break;
            i++;
        }
        
        res *= sign;
        
        if(res < INT_MIN)
            res = INT_MIN;
        if(res > INT_MAX)
            res = INT_MAX;
        
        return (int)res;
    }
};