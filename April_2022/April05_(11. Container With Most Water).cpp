class Solution {
public:
    int maxArea(vector<int>& h) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int l = 0, r = h.size() - 1, max_area = INT_MIN;
        
        while(l < r)
        {
            max_area = max(max_area, (r - l) * min(h[l], h[r]));
            
            // we directly eliminate h[l]
            // Why??
            // considering l ... r-1
            // if h[r-1] > h[l] : area = h[l] * (r-l-1);
            // if h[r-1] <= h[l] : area = h[r-1] * (r-l-1); as h[r-1] < h[l] < h[r]
            
            // these both areas will be smaller so we don't need to consider
            
            // Also in case of equivalent heights, it doesn't matter whether we move
            // l or r as
            
            // initial area = (r-l) * h[r]
            // moving l :
            // assume h[l+1] > h[l] so area = (r-l-1) * h[r] smaller
            // assume h[l+1] < h[l] so area = (r-l-1) * (h[l+1] < h[r]) smaller
            
            // moving r :
            // assume h[r-1] > h[r] so area = (r-l-1) * h[r] smaller
            // assume h[r-1] < h[r] so area = (r-l-1) * (h[r-1] < h[r]) smaller
            if(h[l] < h[r])
            {
                l++;
            }
            
            else
            {
                r--;
            }
        }
        
        return max_area;
    }
};