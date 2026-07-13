class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       vector<int> v;
       queue<int> q;
       for(int i=1;i<=9;i++){
        q.push(i);
       } 
       while(!q.empty()){
        int val=q.front();
        q.pop();
        int last=val%10;
        if(last==9) continue;
        val=val*10+(last+1);
        if(val<=high){
            q.push(val);
            if(val>=low){
                v.push_back(val);
            }
        }
       }
       sort(v.begin(),v.end());
       return v;
    }
};