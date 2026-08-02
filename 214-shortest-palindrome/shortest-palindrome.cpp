class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        string t=s+"$"+rev;
        int m=t.size();
        vector<int> lps(m,0);
        int len=0;
        int i=1;
        while(i<m){
            if(t[i]==t[len]){
                lps[i++]=++len;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else i++;
            }
        }
        int l=lps[m-1];
        string rem=rev.substr(0,n-l);
        return rem+s;
    }
};