class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // there is atleast one element with freq greater than n/2
        
        int setBits[32];
        memset(setBits, 0, sizeof(setBits));
        
        for(int &x : nums)
        {
            for(int j=31; j>=0; j--)
            {
                if(((1LL<<j) & x) != 0)
                    setBits[j]++;
            }
        }
        
        int ans = 0;
        
        for(int i=31; i>=0; i--)
        {
            if(setBits[i] > (n/2))
        }
    }
};