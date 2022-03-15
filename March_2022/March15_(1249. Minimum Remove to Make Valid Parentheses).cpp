class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
     
        vector<int> take(s.size(), 1);
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ')' && st.empty())
                take[i] = 0;
            else if(s[i] == ')' && !st.empty())
                st.pop();
            else if(s[i] == '(')
                st.push(i);
        }
        
        while(!st.empty())
            take[st.top()] = 0, st.pop();
        
        string ans = "";
        
        for(int i=0; i<s.size(); i++)
        {
            if(take[i])
                ans += s[i];
        }
        return ans;
    }
};