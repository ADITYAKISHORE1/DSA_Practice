class KthLargest {
    priority_queue<int> pq;
    int K;
   public:
    KthLargest(int k, vector<int>& nums) {
        for(auto& i:nums){
            pq.push(i);
        }
        K=k;
    }

    int add(int val) {
        pq.push(val);
        vector<int> v;
        int i=0;
        while(i<K-1){
            v.push_back(pq.top());
            pq.pop();
            i++;
        }
        i=pq.top();
        for(auto& i:v) pq.push(i);
        return i;
    }
};
