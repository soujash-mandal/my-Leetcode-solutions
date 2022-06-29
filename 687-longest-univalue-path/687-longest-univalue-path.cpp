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
    
    int res=1;
    
    int fun(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        int l,r;
        l=fun(root->left);
        r=fun(root->right);
        
        int x=root->val;
        
        if(root->left!=NULL && root->right!=NULL && x==root->left->val && x==root->right->val)
        {
            res=max(res,1+l+r);
            return 1+max(l,r);
        }
        if(root->left!=NULL && x==root->left->val)
        {
            res=max(res,1+l);
            return 1+l;
        }
        if(root->right!=NULL && x==root->right->val)
        {
            res=max(res,1+r);
            return 1+r;
        }
        
        return 1;
        
    }
    int longestUnivaluePath(TreeNode* root) {
        int x=fun(root);
        return res-1;
    }
};