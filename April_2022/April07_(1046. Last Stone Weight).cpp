class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(int &x : stones)
            pq.push(x);
        
        while(pq.size() > 1)
        {
            int u = pq.top();
            pq.pop();
            
            int v = pq.top();
            pq.pop();
            
            if(u != v)
            {
                pq.push(u - v);
            }
        }
        
        if(pq.empty())
            return 0;
        return pq.top();
    }
};