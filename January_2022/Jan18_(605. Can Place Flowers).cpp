class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev, next, ans = 0;
        int k = flowerbed.size();
        for(int i=0; i<k; i++)
        {
            if(flowerbed[i] == 1)
                continue;
            
            next = ((i == k-1)?(0):(flowerbed[i+1]));
            prev = ((i == 0)?(0):(flowerbed[i-1]));
            
            if(prev == 0 && next == 0)
                ans++, flowerbed[i] = 1;
        }
        return (ans >= n);
    }
};