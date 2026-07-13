class Solution {
    vector<int> computeZ(string s){
        int n=s.size();
        vector<int> z(n,0);
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i>r){
                l=i;
                r=i;
                while(r<n and s[r]==s[r-l]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }else{
                int i1=i-l;
                if(z[i1]+i<r+1){
                    z[i]=z[i1];
                }else{
                    l=i;
                    while(r<n and s[r]==s[r-l]){
                        r++;
                    }
                    z[i]=r-l;
                    r--;
                }
            }
        }
        return z;
    }
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        vector<int> z=computeZ(needle+"$"+haystack);
        for(int i=0;i<z.size();i++){
            if(z[i]==n){
                return i-n-1;
            }
        }
        return -1;
    }
};