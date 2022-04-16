class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int f_r = 0, l_r = n-1, f_c = 0, l_c = n-1;
        
        vector<vector<int>> mat(n, vector<int> (n));
        
        int val = 1;
        
        while(f_r <= l_r && f_c <= l_c)
        {
            for(int j=f_c; j<=l_c; j++)
                mat[f_r][j] = val++;
            
            f_r++;
            
            if(f_r > l_r)
                break;
            
            for(int i=f_r; i<=l_r; i++)
                mat[i][l_c] = val++;
            
            l_c--;
            
            if(f_c > l_c)
                break;
            
            for(int j=l_c; j>=f_c; j--)
                mat[l_r][j] = val++;
            
            l_r--;
            
            if(f_r > l_r)
                break;
            
            for(int i=l_r; i>=f_r; i--)
                mat[i][f_c] = val++;
            
            f_c++;
            
            if(f_c > l_c)
                break;
        }
        
        return mat;
    }
};