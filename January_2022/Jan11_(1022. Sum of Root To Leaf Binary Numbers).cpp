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
    int res;
    void rec(TreeNode *root, int sum)
    {
        if(!root){
            return;
        }
        
        sum = (sum * 2) + root->val;
        
        if(!root->left && !root->right)
        {
            res += sum;
            return;
        }
        rec(root->left, sum);
        rec(root->right, sum);
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        res = 0;
        rec(root, 0);
        return res;
    }
};