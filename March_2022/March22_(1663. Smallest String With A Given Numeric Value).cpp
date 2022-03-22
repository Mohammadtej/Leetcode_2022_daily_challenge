class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        
        for(int i=n-1; i>=0; i--)
        {
            if(k >= 25)
            {
                k -= 25;
                res[i] = 'z';
            }
            else
            {
                res[i] = (char)('a' + k);
                break;
            }
        }
        
        return res;
    }
};