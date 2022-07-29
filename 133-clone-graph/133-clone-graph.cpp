/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> mp;
    vector<Node*> graph;
    
    void dfs(Node* node,vector<bool>& vis)
    {
        if(vis[node->val]) return;
        
        vis[node->val]=true;
        graph.push_back(node);
        
        Node* root=new Node(node->val);
        mp[node]=root;
        
        for(int i=0;i<node->neighbors.size();i++)
        {
            dfs(node->neighbors[i],vis);
        }
    }
    
//     void joinGraph(Node* node,vector<bool>& vis)
//     {
//         if(vis[node->val]) return;
        
//         vis[node->val]=true;
        
//         // Node* root=new Node(node->val);
//         // mp[node]=root;
        
//         for(int i=0;i<node->neighbors.size();i++)
//         {
//             mp[node]->neighbors.push_back(mp[node->neighbors[i]]);
//             dfs(node->neighbors[i],vis);
//         }
//     }
    
    
    Node* cloneGraph(Node* node) {
        
        if(node==NULL) return NULL;
        
        
        vector<bool> vis(101,false);
        dfs(node,vis);
        // for(int i=0;i<101;i++)vis[i]=false;
        // joinGraph(node,vis);
        
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i]->neighbors.size();j++)
                mp[graph[i]]->neighbors.push_back(mp[graph[i]->neighbors[j]]);
        }
        
        return mp[node];
    }
};