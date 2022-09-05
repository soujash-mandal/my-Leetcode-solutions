/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        vector<vector<int>> res;
        
        while(!q.empty())
        {
            if(q.front()==NULL) break;
            vector<int> temp;
            while(q.front()!=NULL)
            {
                Node* head=q.front();
                temp.push_back(head->val);
                q.pop();
                
                vector<Node*>child=head->children;
                
                for(int i=0;i<child.size();i++)
                {
                    if(child[i]!=NULL)
                    {
                        q.push(child[i]);
                    }
                }
                                            
            }
            q.pop();
            q.push(NULL);
            res.push_back(temp);
            
        }
        
        return res;
    }
};