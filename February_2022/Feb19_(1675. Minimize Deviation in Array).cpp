class Solution {
public:
    #define min_element(s) *(s.begin())
    #define max_element(s) *(prev(s.end(), 1))
    int minimumDeviation(vector<int>& nums) {
        multiset<int> ms;
        
        for(int x : nums)
        {
            if(x%2 == 1)
                ms.insert(x * 2);
            else
                ms.insert(x);
        }
        
        int maxm = max_element(ms); 
        int res = INT_MAX;
        while(maxm % 2 == 0)
        {
            res = min(res, max_element(ms) - min_element(ms));
            ms.erase(maxm);
            maxm /= 2;
            ms.insert(maxm);
            
            maxm = max_element(ms);
        }
        
        return min(res, (max_element(ms) - min_element(ms)));
    }
};