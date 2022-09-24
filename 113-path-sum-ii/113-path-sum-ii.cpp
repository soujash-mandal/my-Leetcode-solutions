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
    vector<vector<int>> ans;
    void fun(TreeNode* root, int targetSum,vector<int> temp)
    {
        if(root==NULL && targetSum==0)
        {
            ans.push_back(temp);
            return;
        }
        if(root==NULL)
        {
            return;
        }
        
        temp.push_back(root->val);
        if(root->left==NULL)
        {
            fun(root->right,targetSum-root->val,temp);
            return;
        }
        if(root->right==NULL)
        {
            fun(root->left,targetSum-root->val,temp);
            return;
        }
        fun(root->right,targetSum-root->val,temp);
        fun(root->left,targetSum-root->val,temp);
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return ans;
        vector<int> temp;
        fun(root,targetSum,temp);
        return ans;
        
    }
};