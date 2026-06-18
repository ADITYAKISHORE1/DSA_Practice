class Solution {
    int strDiff(string& s,string& t){
        int cnt=0;
        for(int i=0;i<8;i++){
            cnt+=(s[i]!=t[i]);
        }
        return cnt;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n=bank.size();
        vector<int> dist(n+1,1e9);
        queue<pair<int,string>> q;
        q.push({0,startGene});
        dist[0]=0;
        while(!q.empty()){
            auto& [it,tm]=q.front();
            q.pop();
            for(int i=0;i<n;i++){
                if(strDiff(tm,bank[i])==1 and dist[i+1]>dist[it]+1){
                    dist[i+1]=dist[it]+1;
                    q.push({i+1,bank[i]});
                }
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(bank[i]==endGene){
                ans=dist[i+1];
                break;
            }
        }
        return (ans==1e9)?-1:ans;
    }
};