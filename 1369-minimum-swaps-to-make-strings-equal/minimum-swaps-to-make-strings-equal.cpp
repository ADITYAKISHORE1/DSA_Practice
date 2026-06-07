class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n=s2.size();
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='x') x++;
            else y++;
            if(s2[i]=='x') x++;
            else y++;
        }
        if(x&1 or y&1) return -1;
        int xy=0,yx=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='x' and s2[i]=='y') xy++;
            else if(s1[i]=='y' and s2[i]=='x') yx++;
        }
        return xy/2+yx/2+(xy%2)+(yx%2);
    }
};