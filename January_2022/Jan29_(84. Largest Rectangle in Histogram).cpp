class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        
        stack<int> st;
        int n = h.size();
        vector<int> right(n, n), left(n, -1);
        
        st.push(n-1);
        
        for(int i=n-2; i>=0; i--)
        {
            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();
            if(!st.empty())
                right[i] = st.top();
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        st.push(0);
        
        for(int i=1; i<n; i++)
        {
            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();
            if(!st.empty())
                left[i] = st.top();
            st.push(i);
        }
        
        int max_area = INT_MIN, curr;
        
        for(int i=0; i<n; i++)
        {
            curr = h[i] * (right[i] - left[i] - 1);
            max_area = max(max_area, curr);
        }
        return max_area;
    }
};