class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        
        int curr_sum = 0, ans = 0;
        
        for(int x : nums)
        {
            curr_sum += x;
            
            if(curr_sum == k)
                ans++;
            if(um.count(curr_sum - k) != 0)
                ans += um[curr_sum - k];
            um[curr_sum]++;
        }
        
        return ans;
    }
};