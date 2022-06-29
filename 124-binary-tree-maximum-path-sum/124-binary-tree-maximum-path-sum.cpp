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
    int res=0;
    int maxnum=INT_MIN;
    
    int fun(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        maxnum=max(maxnum,root->val);
        
        int l=fun(root->left);
        int r=fun(root->right);
        
        res=max(res,l+r+root->val);
        
        return max(root->val+max(l,r),0);
    }
    
    int maxPathSum(TreeNode* root) {
        int x=fun(root);
        if(maxnum<=0) return maxnum;
        return res;
    }
};