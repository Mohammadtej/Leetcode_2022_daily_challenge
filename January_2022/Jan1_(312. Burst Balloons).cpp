class Solution {
public:
    int dp[510][510];
    int rec(vector<int> &v, int l, int r)
    {
        if(l > r)
            return 0;
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int ans = INT_MIN;
        for(int i=l; i<=r; i++)
        {
            int tp = (v[l-1] * v[i] * v[r+1]) + rec(v, l, i-1) + rec(v, i+1, r);
            ans = max(tp, ans);
        }
        
        dp[l][r] = ans;
        return ans;
    }
    
    
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        vector<int> v;
        v.push_back(1);
        
        for(int x : nums)
            v.push_back(x);
        v.push_back(1);
        
        return rec(v, 1, nums.size());
    }
};