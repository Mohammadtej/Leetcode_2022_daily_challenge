class Solution {
public:
    // up left down right
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    map<int, int> mp;
  
    
    bool isRobotBounded(string instr) {
        int it = 4;
        mp[0] = 0;
        mp[-90] = 1;
        mp[-180] = 2;
        mp[-270] = 3; 
        mp[90] =3;
        mp[180] = 2;
        mp[270] = 1;
    
        int st_x = 0, st_y = 0, x = 0, y = 0, deg = 0, k = 0, n = instr.size();
        char ch;
        int disp = 0;
        for(int i=0; i<it; i++)
        {
            for(int j=0; j<n; j++)
            {
                ch = instr[j];
                if(ch == 'G')
                {
                    x += dx[k];
                    y += dy[k];
                }
                else if(ch == 'L')
                {
                    deg -= 90;
                    k = mp[deg%360];
                }
                else
                {
                    deg += 90;
                    k = mp[deg%360];
                }
            }
            disp = abs(st_x - x);            
            disp += abs(st_y - y);
            
            if(disp <= 0)
                return 1;

        }
        return 0;
    }
};