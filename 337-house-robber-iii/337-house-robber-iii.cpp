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
    map<TreeNode*,int> dp;
    
    int fun(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        if(dp[root]!=0) return dp[root];
        // if(dp.find(root)!=dp.end()) return 0;
        
        int res1=fun(root->left)+fun(root->right);
        
        int res2=root->val;
        
        if(root->left!=NULL)
        {
            res2+=fun(root->left->left)+fun(root->left->right);
        }
        
        if(root->right!=NULL)
        {
            res2+=fun(root->right->left)+fun(root->right->right);
        }
        
        
        return dp[root]=max(res1,res2);
    }
    int rob(TreeNode* root) {
        // vector<TreeNode*
        
        return fun(root);
    }
};