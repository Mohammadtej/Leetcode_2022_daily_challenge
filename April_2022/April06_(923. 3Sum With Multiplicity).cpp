class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> mp;
        
        for(int &x : arr)
            mp[x]++;
        
        
        long ans = 0, MOD = 1e9 + 7;
        
        for(auto it : mp)
        {
            for(auto it2 : mp)
            {
                int i = it.first, j = it2.first, k = target - i - j;
                
                if(mp.count(k) == 0)
                    continue;
                
                if(i == j && j == k)
                {
                    ans += (mp[i] * (mp[i] - 1) * (mp[i] - 2))/6;
                    ans %= MOD;
                }
                
                else if(i == j)
                {
                    ans += (mp[k] * mp[i] * (mp[i] - 1))/2;
                    ans %= MOD;
                }
                
                else if(i < j && j < k)
                {
                    ans += (mp[i] * mp[j] * mp[k]);
                    ans %= MOD;
                }
            }
        }
            
        return ans;
    }
};