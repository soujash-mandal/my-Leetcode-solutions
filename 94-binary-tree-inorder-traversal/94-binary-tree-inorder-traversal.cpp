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
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root==NULL)
        {
            vector<int> blank;
            return blank;
        }
            
        
        vector<int> leftpart=inorderTraversal(root->left);
        leftpart.push_back(root->val);
        vector<int> rightpart=inorderTraversal(root->right);
        
        leftpart.insert( leftpart.end(), rightpart.begin(), rightpart.end() );
        
        return leftpart;
    }
};