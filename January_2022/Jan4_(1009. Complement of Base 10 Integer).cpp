class Solution {
public:
    int bitwiseComplement(int n) {
        int i, ans = 0;
        
        if(n == 0)
            return 1;
        
        for(i=31; i>=0; i--)
        {
            if(((1LL<<i) & n) != 0)
            {
                break;
            }
        }
        
        for(; i>=0; i--)
        {
            if(((1LL<<i) & n) == 0)
                ans += (1LL<<i);
        }
        
        return ans;
    }
};