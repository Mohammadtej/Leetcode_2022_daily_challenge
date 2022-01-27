/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode *t, vector<int> &a)
    {
        if(t == NULL)
            return;
        inorder(t->left, a);
        a.push_back(t->val);
        inorder(t->right, a);
        return;
    }
    
    void merge(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        
        while(i < n && j < m)
        {
            if(a[i] < b[j])
                c.push_back(a[i]), ++i;
            else
                c.push_back(b[j]), ++j;
        }
        
        while(i < n)
        {
            c.push_back(a[i]), ++i;
        }
        
        while(j < m)
        {
            c.push_back(b[j]), ++j;
        }
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b, c;
        inorder(root1, a);
        inorder(root2, b);
        merge(a, b, c);
        return c;
    }
};