class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            if(lights[i]==0) continue;
            int l=max(i-lights[i],0);
            int r=min(n,i+lights[i]+1);
            v[l]+=1;
            if(r<n) v[r]+=-1;
        }
        int pref=v[0];
        for(int i=1;i<n;i++){
            v[i]+=pref;
            pref=v[i];
        }
        int cnt=0;
        for(int i=1;i<n-1;i++){
            if(v[i]==0 and v[i-1]==0 and v[i+1]==0){
                v[i-1]=1;
                v[i]=1;
                v[i+1]=1;
                cnt++;
            }
        }
        for(int i=1;i<n;i++){
            if(v[i]==0 and v[i-1]==0){
                v[i-1]=1;
                v[i]=1;
                cnt++;
            }
        }
        for(auto& i:v) cnt+=(i==0);
        return cnt;
    }
};