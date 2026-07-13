class Solution {    
    vector<int> computeZ(string& s){
        int n=s.size();
        vector<int> z(n,0);
        int l=0,r=0;
        for(int k=1;k<n;k++){
            if(k>r){
                l=k;
                r=k;
                while(r<n and s[r]==s[r-l]) r++;
                z[k]=r-l;
                r--;
            }else{
                if(z[k-l]+k<r+1){
                    z[k]=z[k-l];
                }else{
                    l=k;
                    while(r<n and s[r]==s[r-l]) r++;
                    z[k]=r-l;
                    r--;
                }
            }
        }
        return z;
    }
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        string s=needle+"$"+haystack;
        vector<int> z=computeZ(s);
        for(int i=0;i<z.size();i++){
            if(z[i]==n){
                return i-n-1;
            }
        }
        return -1;
    }
};