class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> um;
        
        int ans = 0, curr_sum = 0, n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            curr_sum += (nums[i] == 0 ? (-1) : (1));
            
            if(curr_sum == 0)
                ans = max(ans, i+1);
            
            if(um.find(curr_sum) != um.end())
            {
                ans = max(ans, i+1 - um[curr_sum]);
            }
            else
            {
                um[curr_sum] = i+1;
            }
        }
        
        return ans;
    }
};