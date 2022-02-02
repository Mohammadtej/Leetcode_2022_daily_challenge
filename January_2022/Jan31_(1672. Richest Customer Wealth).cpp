class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        int r = acc.size(), c = acc[0].size();
        
        vector<vector<int>> pre(r, vector<int> (c, 0));
        
        for(int i=0; i<r; i++)
            pre[i][0] = acc[i][0];
        
        for(int i=0; i<r; i++)
        {
            for(int j=1; j<c; j++)
            {
                pre[i][j] = pre[i][j-1] + acc[i][j];
            }
        }
        
        int maxm = INT_MIN;
        
        for(int i=0; i<r; i++)
            maxm = max(maxm, pre[i][c-1]);
        return maxm;
    }
};