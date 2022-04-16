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
    int sum;
    
    void rec(TreeNode *root)
    {
        if(root == NULL)
            return;
        rec(root->right);
        
        int v = root->val;
        
        root->val += sum;
        
        sum += v;
        
        rec(root->left);
        
        return;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        rec(root);
        return root;
    }
};