class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {  
        vector<int> rem(60, 0);
        
        for(int x : time)
            rem[x%60]++;
        
        int ans = 0;
        
        ans += (rem[0] * (rem[0] - 1))/2;
        
        for(int i=1; i<30; i++)
        {
            ans += (rem[i] * rem[60 - i]);
        }
        
        ans += (rem[30] * (rem[30] - 1))/2;
        
        return ans;
    }
};