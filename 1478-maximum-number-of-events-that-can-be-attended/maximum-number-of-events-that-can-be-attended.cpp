class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<>> pq;
        int day=0;
        int cnt=0;
        int i=0;
        while(!pq.empty() or i<n){
            if(pq.empty()){
                day=max(day,events[i][0]);
            }
            while(i<n and events[i][0]<=day){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() and day>pq.top()){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                day++;
                cnt++;
            }
        }
        return cnt;
    }
};