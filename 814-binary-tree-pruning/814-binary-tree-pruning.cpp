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
    bool check(TreeNode* root)
    {
        if(root==NULL) return false;
        if(root->val==1) return true;
        return check(root->left)||check(root->right);
    }
    void fun(TreeNode* &root)
    {
        if(root==NULL)
            return;
       
        
            if(check(root->left)==false)
            {
                root->left=NULL;
            }
            if(check(root->right)==false)
            {
                root->right=NULL;
            }
        
        fun(root->left);
        fun(root->right);
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(check(root)==false)
            return NULL;
        fun(root);
        return root;
    }
};