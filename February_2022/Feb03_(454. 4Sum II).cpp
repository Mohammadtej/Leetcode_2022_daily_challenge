class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int n = nums1.size();
        
        unordered_map<long, int> um1, um2;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                um1[nums1[i] + nums2[j]]++;
                um2[nums3[i] + nums4[j]]++;
            }
        }
        
        int ans = 0;
        for(auto x : um1)
        {
            if(um2.find(-x.first) != um2.end())
                ans += (x.second * um2[-x.first]);
        }
        
        return ans;
    }
};