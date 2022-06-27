class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        vector<vector<int>> diff(n,vector<int>(n));
        vector<vector<int>> graph(n);
        
        int n1=t.size();
        
        for(int i=0;i<n1;i++)
        {
            graph[t[i][0]-1].push_back(t[i][1]-1);
            diff[t[i][0]-1][t[i][1]-1]=t[i][2];
        }
        
        vector<int> time(n,INT_MAX);
        
        queue<int> q;
        q.push(k-1);
        time[k-1]=0;
        
        
        while(q.size())
        {
            int n1=q.size();
            for(int i=0;i<n1;i++)
            {
                int node=q.front();
                q.pop();
                for(int j=0;j<graph[node].size();j++)
                {
                    if(time[node]+diff[node][graph[node][j]]<time[graph[node][j]])
                    {
                        time[graph[node][j]]=time[node]+diff[node][graph[node][j]];
                        q.push(graph[node][j]);
                    }
                }
            }
        }
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(time[i]==INT_MAX) return -1;
            res=max(res,time[i]);
        }
        
        return res;
        
    }
};