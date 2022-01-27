class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int digit = 1; digit <= 10; digit++)
        {
            for(int start = 1; start <= 9; start++)
            {
                int t = start;
                int num = 0, curr = digit;
                while(t != 10 && curr > 0)
                {
                    num = num * 10 + t;
                    t++;
                    curr--;
                }
                
                if(curr == 0 && num >= low && num <= high)
                {
                    res.push_back(num);
                }
            }
        }
        
        return res;
    }
};