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
    void rec(TreeNode *root, TreeNode *&ans)
    {
        if(root == NULL)
            return;
        rec(root->left, ans);
        
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        
        rec(root->right, ans);
        
        return;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *tmp, *ans = new TreeNode();
        
        tmp = ans;
        
        rec(root, ans);
        
        return tmp->right;
    }
};