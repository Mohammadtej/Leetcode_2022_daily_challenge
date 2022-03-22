class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
        // here we want to make either top or bottom same with minimum number of moves
        // so we try with 1 ... 6 first to bring into the top and then into the bottom
        
        // first trying to bring 1 ... 6 into the top
        
        int ans = INT_MAX;
        
        vector<int> candidates{tops[0], bottoms[0]};
        
        for(int j : candidates)
        {
            int moves = 0;
            for(int i=0; i<n; i++)
            {
                if(tops[i] == j)
                    continue;
                if(bottoms[i] == j)
                    moves++;
                else
                    moves = -2 * n;
            }
            
            if(moves >= 0)
                ans = min(ans, moves);
        }
        
        for(int j : candidates)
        {
            int moves = 0;
            
            for(int i=0; i<n; i++)
            {
                if(bottoms[i] == j)
                    continue;
                if(tops[i] == j)
                    moves++;
                else
                    moves = -2 * n;
            }
            
            if(moves >= 0)
                ans = min(ans, moves);
        }
        
        return (ans != INT_MAX ? (ans) : (-1));
    }
};