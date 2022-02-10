class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2, i = 0, j = 0, n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            nums[j++] = nums[i];
            
            if(i+1 < n && nums[i+1] == nums[j-1])
            {
                nums[j++] = nums[i++];
                
                while(i+1 < n && nums[i+1] == nums[j-1])
                    i++;
            }
        }
        
        return j;
    }
};