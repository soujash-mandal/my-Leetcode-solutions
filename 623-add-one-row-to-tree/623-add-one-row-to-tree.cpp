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
    
    int d;
    
    void solve(TreeNode* root,int val,int currDepth)
    {
        if(root==NULL) return;
        
        if(currDepth==d-1)
        {
            TreeNode* l=root->left;
            TreeNode* r=root->right;
            
            TreeNode* nodeLeft=new TreeNode(val);
            TreeNode* nodeRight=new TreeNode(val);
            
            root->left=nodeLeft;
            root->right=nodeRight;
            
            nodeLeft->left=l;
            nodeRight->right=r;
            
            return;
        }
        
        solve(root->left,val,currDepth+1);
        solve(root->right,val,currDepth+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1)
        {
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        
        d=depth;
        solve(root,val,1);
        
        return root;
    }
};

// traverse till (depth -1)
// root