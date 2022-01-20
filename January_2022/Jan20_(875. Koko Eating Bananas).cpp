class Solution {
public:
    bool check(int x, vector<int> &v, int h)
    {
        int cnt = 0;
        
        for(int i=0; i<v.size() && cnt <= h+1; i++)
        {
            cnt += v[i]/x;
            
            if(v[i]%x != 0)
                cnt++;
        }
        
        return (cnt <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // pattern FFFF...TTTT
        
        int l = 0, r = *max_element(piles.begin(), piles.end());
        
        while(r > (l+1))
        {
            int mid = (l + r)/2;
            
            if(check(mid, piles, h))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        
        return r;
    }
};