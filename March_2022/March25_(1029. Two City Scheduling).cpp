class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& cost) {
        
        // in this question basically we need to allocate in such a way that the sum total is as minimum as possible
        // for example there are 2 elements [40, 2000] and [10, 20] then the 1st should select going to a and the second to b thus total cost being = 40 + 20 = 60
        
        // so we create a vector to store first the difference between the costs of travelling to a and b and then the index.
        
        // the difference will help us in sorting as more negative it is the more we are saving travelling to a rather than b
        
        vector<array<int, 2>> v;
        
        // stores the total sum cost of b
        int tot_b = 0;
        
        for(int i=0; i<cost.size(); i++)
        {
            tot_b += cost[i][1];
            v.push_back({cost[i][0] - cost[i][1], i});
        }
        
        sort(v.begin(), v.end());
        
        // ans
        int tot_cost = 0;
        
        for(int i=0; i<cost.size()/2; i++)
        {
            tot_cost += cost[v[i][1]][0];
            
            // here we are selecting travelling to a so we substract its cost from b
            tot_b -= cost[v[i][1]][1];
        }
        
        tot_cost += tot_b;
        
        return tot_cost;
    }
};