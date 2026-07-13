class Solution {
    const int base=31;
    const int mod=1e9+7;
bool rabinKarp(string st,string tar){
    int n=tar.size();
    long long tarHash=0;
    long long power = 1;

    for(int i = 0; i < n - 1; i++)
        power = (power * base) % mod;
    for(auto& c:tar){
        tarHash=(tarHash*base+(c-'a'+1))%mod;
    }
    long long curHash=0;
    int i=0;
    for(int j=i;j<st.size();j++){
        if(j-i+1>n){
            curHash=(curHash-1LL*(st[i]-'a'+1)*power%mod+mod)%mod;
            i++;
        }
        curHash=(curHash*base+(st[j]-'a'+1))%mod;
        if(curHash==tarHash){
            return true;
        }
    }
    return false;
}
public:
    int repeatedStringMatch(string a, string b) {
        int m=b.size();
        int cnt=0;
        string s;
        while(s.size()<m){
            s+=a;
            cnt++;
        }
        if(rabinKarp(s,b)) return cnt;
        if(rabinKarp(s+a,b)) return cnt+1;
        return -1;
    }
};