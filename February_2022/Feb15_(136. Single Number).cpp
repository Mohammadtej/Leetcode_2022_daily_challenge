class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorm = 0;
        
        for(int x : nums)
            xorm ^= x;
        return xorm;
    }
};