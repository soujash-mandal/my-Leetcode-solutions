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
    bool fun(TreeNode* root,int a,int b)
    {
        if(root==NULL) return true;
        
        if(root->val>=a && root->val<=b)
        {
            if(root->val==INT_MAX)
            {
                if(root->right!=NULL) return false;

            }
            if(root->val==INT_MIN)
            {
                if(root->left!=NULL) return false;

            }
            
            bool res=true;
            if(root->val!=INT_MAX) res=res&fun(root->right,root->val+1,b);
            if(root->val!=INT_MIN) res=res&fun(root->left,a,root->val-1);
            
            
            return res;
        }
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return fun(root,INT_MIN,INT_MAX);
    }
};