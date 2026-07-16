class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        priority_queue<int,vector<int>,greater<>> pq;
        for(auto& i:nums1) pq.push(i);
        for(auto& i:nums2) pq.push(i);
        double median;
        double a;
        while(pq.size()>(n+m+1)/2){
            a=pq.top();
            pq.pop();
        }
        if((m+n)%2==1){
            return (double)pq.top();
        }
        return (a+pq.top())/2.0;
    }
};