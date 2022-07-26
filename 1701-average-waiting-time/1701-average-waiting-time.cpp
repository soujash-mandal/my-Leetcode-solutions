class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int n=c.size();
        
        int currtime=c[0][0];
        
        double res=0;
        
        for(int i=0;i<n;i++)
        {
            currtime=max(currtime,c[i][0]);
            
            int extratime=(currtime-c[i][0]);
            currtime+=c[i][1];
            
            
            
            int foodtime=c[i][1];
            
            res+=foodtime+extratime;
        }
        
        return res/(1.0*n);
    }
};

// 2+  ( extra time= 3-2=1  )+5  + (8-4)+3

// currtime = >  1, 3, 8
// extra time => 0, 1, 4
// food time  => 2, 5, 3

// waiting time => 2,6,7

//