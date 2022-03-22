class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> st;
        
        vector<int> v(s.size(), 0);
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                int j = st.top();
                st.pop();
                
                if(i - j == 1)
                    v[j] = 1;
                else
                {
                    int sum = 0;
                    
                    for(int k=j+1; k<i; k++)
                        sum += v[k];
                    v[j] = 2 * sum;
                    
                    for(int k=j+1; k<i; k++)
                        v[k] = 0;
                }
                
                if(st.empty())
                    score += v[j];
            }
        }
        
        
        return score;
    }
};