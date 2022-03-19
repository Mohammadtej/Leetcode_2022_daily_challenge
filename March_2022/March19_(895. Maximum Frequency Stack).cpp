class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> st;
    
    int max_freq;
    
    FreqStack() {
        freq.clear();
        st.clear();
        max_freq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        st[freq[val]].push(val);
        max_freq = max(max_freq, freq[val]);
    }
    
    int pop() {
        int ans = st[max_freq].top();
        st[max_freq].pop();
        
        if(st[max_freq].empty())
            max_freq--;
        
        freq[ans]--;
        
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */