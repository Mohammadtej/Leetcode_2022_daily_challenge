class Solution {
public:
    int n, m;
    int dp[71][71][71];
    int dy[3] = {-1, 0, 1};

    int dfs(int x, int y1, int y2, vector<vector<int>>& grid)
    {
        int sum = 0;
        
        if(y1 == y2)
            sum += grid[x][y1];
        else
            sum += grid[x][y1], sum += grid[x][y2];
        
        if(x == (n-1))
            return sum;
        
        if(dp[x][y1][y2] != -1)
            return dp[x][y1][y2];
        
        int ans = INT_MIN;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if((y1 + dy[i]) >= 0 && (y1 + dy[i]) < m && (y2 + dy[j]) >= 0 && (y2 + dy[j]) < m )
                    ans = max(ans, sum + dfs(x + 1, y1 + dy[i], y2 + dy[j], grid));
            }
        }
        
        return (dp[x][y1][y2] = ans);
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();   
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, m-1, grid);
    }
};