class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // we are told to find the next greater sequence
        // if we observe carefully if there exist a pair a[i] < a[i+1]
        // then they can be swapped to form a larger number
        
        // But we also need to take care of nearest greater sequence, for 
        // that the pair should be as rightmost as possible so that it covers the 
        // significant digits
        
        // also after j the vector should be sorted to form the nearest
        
        // if there exist an element after j such that it is just greater than a[i]
        // but it is less than a[i+1] then optimally it is to swap them
        
        int lastInc = -1;
        int n = nums.size();
        
        for(int i=1; i<n; i++)
        {
            if(nums[i] > nums[i-1])
            {
                lastInc = i;
            }
        }
        
        if(lastInc == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int index = lastInc;
        
        for(int i=lastInc + 1; i<n; i++)
        {
            if(nums[i] > nums[lastInc - 1] && nums[i] < nums[index])
            {
                index = i;
            }
        }
        
        swap(nums[lastInc - 1], nums[index]);
        
        sort(nums.begin() + lastInc, nums.end());
        return;
    }
};