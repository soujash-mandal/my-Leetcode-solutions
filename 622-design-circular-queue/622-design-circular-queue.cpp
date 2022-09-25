class MyCircularQueue {
public:
    vector<int> v;
    int start;
    int end;
    int n;
    MyCircularQueue(int k) {
        start=-1;
        end=-1;
        n=k;
        
        vector<int> temp(k);
        v=temp;
    }
    
    bool enQueue(int value) {
        if(start==-1)
        {
            v[0]=value;
            start=0;
            end=1%n;
            return true;
        }
        if(end==start) return false;
        else
        {
            v[end]=value;
            end++;
            end=end%n;
            return true;
        }
        
    }
    
    bool deQueue() {
        if(start==-1) return false;
        else
        {
            start++;
            start=start%n;
            if(start==end)
            {
                start=-1;
                end=-1;
                return true;
            }
            return true;
        }
    }
    
    int Front() {
        if(start==-1) return -1;
        return v[start];
    }
    
    int Rear() {
        if(start==-1) return -1;
        if(end==0) return v[n-1];
        return v[end-1];
    }
    
    bool isEmpty() {
        if(start==-1) return true;
        return false;
    }
    
    bool isFull() {
        if(start==-1) return false;
        if(start==end) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */