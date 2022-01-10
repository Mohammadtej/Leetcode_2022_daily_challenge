class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        
        int i = a.size() - 1, j = b.size() - 1, carry = 0, s;
        
        while(i >= 0 && j >= 0)
        {
            s = (carry + (a[i] - '0') + (b[j] - '0'));
            sum += (s%2 + '0');
            carry = s/2;
            i--; j--;
        }
        
        while(i >= 0)
        {
            s = (carry + (a[i] - '0'));
            sum += (s%2 + '0');
            carry = s/2;
            i--;
        }
        
        while(j >= 0)
        {
            s = (carry + (b[j] - '0'));
            sum += (s%2 + '0');
            carry = s/2;
            j--;
        }
        
        if(carry > 0)
            sum += (carry + '0');
        
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
};