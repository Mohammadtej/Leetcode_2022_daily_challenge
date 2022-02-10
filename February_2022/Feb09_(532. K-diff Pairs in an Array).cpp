class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        set<pair<int, int>> st;
        
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(binary_search(nums.begin() + i + 1, nums.end(), k + nums[i]))
                st.insert({nums[i], nums[i] + k});
        }
        
        return (int)st.size();
    }
};