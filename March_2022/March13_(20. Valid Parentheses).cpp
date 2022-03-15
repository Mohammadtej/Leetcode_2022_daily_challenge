class Solution {
public:
    bool is_opp(char x, char y)
    {
        if(y == '(' && x == ')')
            return 1;
        if(y == '[' && x == ']')
            return 1;
        if(y == '{' && x == '}')
            return 1;
        return 0;
    }
    bool isValid(string s) {
        stack<char> st;
        
        for(char &ch : s)
        {
            if(!st.empty() && is_opp(ch, st.top()))
                st.pop();
            else
                st.push(ch);
        }
        
        return (st.empty());
    }
};