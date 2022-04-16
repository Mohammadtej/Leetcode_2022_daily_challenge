class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        
        for(int &x : nums)
            um[x]++;
        
        vector<int> bucket[nums.size() + 1];
        
        for(auto &x : um)
            bucket[x.second].push_back(x.first);
        
        vector<int> res;
        
        for(int i=nums.size(); i>=1; i--)
        {
            for(int x : bucket[i])
            {
                res.push_back(x);
                
                if(res.size() == k)
                    return res;
            }
        }
        
        return {-1};
    }
};