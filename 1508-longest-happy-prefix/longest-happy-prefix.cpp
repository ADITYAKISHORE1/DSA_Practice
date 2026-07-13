class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> z(n,0);
        int l=0,r=0;
        int maxm=0;
        for(int k=1;k<n;k++){
            if(r<k){
                l=k;
                r=k;
                while(r<n and s[r]==s[r-l]) r++;
                z[k]=r-l;
                r--;
            }else{
                if(k+z[k-l]<=r){
                    z[k]=z[k-l];
                }else{
                    l=k;
                    while(r<n and s[r]==s[r-l]) r++;
                    z[k]=r-l;
                    r--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i+z[i]==n) return s.substr(i,z[i]);
        }
        return "";
    }
};