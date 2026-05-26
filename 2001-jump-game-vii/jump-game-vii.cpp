class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s.back()&1) return false;
        queue<int> q;
        q.push(0);
        int far=0;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            if(v==n-1) return true;
            int l=max(v+minJump,far+1);
            int r=min(n-1,v+maxJump);
            for(int i=l;i<=r;i++){
                if(s[i]=='0'){
                    q.push(i);
                }
            }
            far=max(r,far);
        }
        return false;
    }
}; 