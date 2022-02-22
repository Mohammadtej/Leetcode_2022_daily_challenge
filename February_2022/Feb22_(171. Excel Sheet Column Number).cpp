class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long title = 0, n = columnTitle.size(), powm = 1;
        
        for(int i=n-1; i>=0; i--)
        {
            title += (columnTitle[i] - 'A' + 1) * powm;
            powm *= 26;
        }
        
        return title;
    }
};