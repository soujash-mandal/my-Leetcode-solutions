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
    int fun(TreeNode* root,int maxval)
    {
        if(root==NULL) return 0;
        int count=0;
        if(root->val>=maxval)
        {
            count++;
            maxval=root->val;
        }
        count+=fun(root->left,maxval)+fun(root->right,maxval);
        return count;
    }
    int goodNodes(TreeNode* root) {
        int maxval=root->val;
        int count=1;
        count+=fun(root->left,maxval)+fun(root->right,maxval);
        
        return count;
    }
};