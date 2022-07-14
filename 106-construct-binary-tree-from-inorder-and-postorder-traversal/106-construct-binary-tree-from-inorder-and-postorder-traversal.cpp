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
    int idx=0;
    TreeNode* fun(vector<int>& p,vector<int>& in,int l,int r)
    {
        if(idx==p.size()) return NULL;
        int pos=-1;
        for(int i=l;i<=r;i++)
        {
            if(in[i]==p[idx])
            {
                pos=i;
            }
        }
        
        if(pos==-1) return NULL;
        
        TreeNode* root=new TreeNode(p[idx]);
        idx++;
        root->right=fun(p,in,pos+1,r);
        root->left=fun(p,in,l,pos-1);
        
        
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& p) {
        int n=p.size();
        reverse(p.begin(),p.end());
        return fun(p,in,0,n-1);
    }
};