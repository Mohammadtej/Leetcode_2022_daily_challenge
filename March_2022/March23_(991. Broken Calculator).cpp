class Solution {
public:
    int brokenCalc(int x, int y) {
        
        // Now let's reverse the operation 
        // change y back to x
        // op1 : y = y/2, if y is even
        // op2 : y = y + 1;
        // Now we want to reduce y as fast as possible
        
        int res = 0;
        
        while(y > x)
        {
            y = (y % 2 == 0 ? (y/2) : (y+1));
            res++;
        }
        
        res += (x - y);
        return res;
    }
};