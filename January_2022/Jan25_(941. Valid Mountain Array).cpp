class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
    
        int j = max_element(arr.begin(), arr.end()) - arr.begin();
        
        if(n < 3 || j == n-1 || j == 0)
            return 0;
        bool inc = true, dec = true;
        
        for(int i=0; i<j; i++)
        {
            if(arr[i+1] <= arr[i]){
                inc = false;
                break;
            }
        }
        
        for(int i=j; i<n-1; i++)
        {
            if(arr[i+1] >= arr[i])
            {
                dec = false;
                break;
            }
        }
        
        return (inc == 1 && dec == 1);
    }
};