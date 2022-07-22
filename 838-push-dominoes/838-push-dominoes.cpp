class Solution {
public:
    string pushDominoes(string d) {
        int i=0;
        int n=d.size();
        
        while(i<n)
        {
            while(i<n && d[i]!='.')i++;
            if(i==n) break;
            
            int l=i;
            while(i<n && d[i]=='.')
            {
                i++;
            }
            int r=i;
            
            // cout<<l<<" "<<r<<endl;
            
            bool left=false,right=false;
            if(l>0 && d[l-1]=='R') left=true;
            
            if(r<n && d[r]=='L') right=true;
            
            if(left && right)
            {
                int i1=l;
                int i2=r-1;
                
                while(i2>i1)
                {
                    d[i1]='R';
                    d[i2]='L';
                    i1++;
                    i2--;
                }
            }
            else if(left)
            {
                int i1=l;
                int i2=r-1;
                
                while(i2>=i1)
                {
                    d[i1]='R';
                    i1++;
                }
            }
            else if(right)
            {
                int i1=l;
                int i2=r-1;
                
                while(i2>=i1)
                {
                    d[i2]='L';
                    i2--;
                }
            }
        }
        
        return d;
    }
};