class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        
        int cnt, n = nums.size(), d;
        
        for(int i=0; i<n; i++)
        {
            if(i+1 < n)
            {
                d = nums[i+1] - nums[i];
                int j = i+2;
                cnt = 2;
                
                while(j < n && nums[j] - nums[j-1] == d)
                    cnt++, j++;
                ans += ((cnt - 2) * (cnt - 1))/2;
                
                i = j-2;
            }
        }
        
        return ans;
    }
};