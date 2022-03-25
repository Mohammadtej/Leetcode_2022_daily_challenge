class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int n = people.size();
        
        int i = 0, j = n-1, res = 0;
        
        while(i <= j)
        {
            if(i != j && people[j] + people[i] <= limit)
            {
                res++;
                i++;
                j--;
            }
            
            else
            {
                res++;
                j--;
            }
        }
        
        return res;
    }
};