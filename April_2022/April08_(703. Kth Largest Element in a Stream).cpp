class KthLargest {
public:
    int sz;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        
        sz = k;
        
        for(int x : nums)
        {
            pq.push(x);
        }
        
        while(pq.size() > k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > sz)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */