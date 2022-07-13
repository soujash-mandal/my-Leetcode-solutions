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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<vector<int>> res;
        
        while(!q.empty())
        {
            if(q.front()==NULL) break;
            vector<int> temp;
            while(q.front()!=NULL)
            {
                TreeNode* head=q.front();
                temp.push_back(head->val);
                q.pop();
                
                if(head->left!=NULL)
                {
                    q.push(head->left);
                }
                
                if(head->right!=NULL)
                {
                    q.push(head->right);
                }                             
            }
            q.pop();
            q.push(NULL);
            res.push_back(temp);
            
        }
        
        return res;
    }
};