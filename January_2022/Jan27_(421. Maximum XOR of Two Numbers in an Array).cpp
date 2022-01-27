class Solution {
public:
    /* Reference - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/1723252/A-deatiled-EXPLANATION-that-ever-exists!-With-notes-you-can-Download*/
    struct node{
        int v;
        node *left;
        node *right;
        
        node(int x)
        {
            v = x;
            left = NULL;
            right = NULL;
        }
    };
    
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        node *head = new node(-1), *t = head;
        
        for(int x : nums)
        {
            t = head;
            for(int i=31; i>=0; i--)
            {
                if(((1<<i) & x) != 0)
                {
                    //1 right
                    
                    if(t->right == NULL)
                        t->right = new node(1);
                    t = t->right;
                }
                else
                {
                    //0 left
                    
                    if(t->left == NULL)
                        t->left = new node(0);
                    t = t->left;
                }
            }
        }
        
        
        int maxm = INT_MIN;
        for(int x : nums)
        {
            int n = 0;
            t = head;
            for(int i=31; i>=0; i--)
            {
                if(((1LL<<i) & x) == 0)
                {
                    if(t->right != NULL)
                    {
                        n += 1LL<<i;
                        t = t->right;
                    }
                    else
                    {
                        t = t->left;
                    }
                }
                else
                {
                    if(t->left != NULL)
                    {
                        t = t->left;
                    }
                    else
                    {
                        n += 1LL<<i;
                        t = t->right;
                    }
                }
            }
            
            maxm = max(maxm, (n ^ x));
            
        }
        return maxm;
    }
};