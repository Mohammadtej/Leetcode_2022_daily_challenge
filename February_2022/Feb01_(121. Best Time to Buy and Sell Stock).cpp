class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
                
        int maxm = prices[n-1], profit = INT_MIN;
        for(int i=n-2; i>=0; i--)
        {
            if(prices[i] < maxm)
            {
                profit = max(profit, maxm - prices[i]);
            }
            maxm = max(maxm, prices[i]);
        }
        
        if(profit == INT_MIN)
            profit = 0;
        return profit;
    }
};