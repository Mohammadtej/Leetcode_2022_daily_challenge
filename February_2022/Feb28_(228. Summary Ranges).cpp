class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        string t = "";
        vector<string> v;
        
        
        int prev;
        
        for(int i=0; i<nums.size(); i++)
        {
            t = "";
            t += to_string(nums[i]);
            prev = nums[i];
            
            i++;
            while(i < nums.size() && nums[i] == nums[i-1] + 1)
                i++;
            
            i--;
            
            if(nums[i] != prev)
                t += "->", t += to_string(nums[i]);
            v.push_back(t);
        }
        
        return v;
    }
};