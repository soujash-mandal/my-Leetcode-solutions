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
    void in(TreeNode* root,vector<int>& v)
    {
        if(root==NULL) return;
        
        in(root->left,v);
        v.push_back(root->val);
        in(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        in(root,v);
        set<int> s;
        s.insert(v[0]);
        
        for(int i=1;i<v.size();i++)
        {
            auto it=s.lower_bound(k-v[i]);
            if(it!=s.end())
            {
                if(*it+v[i]==k) return true;
            }
            s.insert(v[i]);
            
        }
        
        return false;
    }
};