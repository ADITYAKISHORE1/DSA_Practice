class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<=n-m;i++){
            string s=haystack.substr(i,m);
            if(s==needle) return i;
        }
        return -1;
    }
};