class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string a=countAndSay(n-1);
        string s;
        char cur=a[0];
        int cnt=1;
        for(int i=1;i<a.size();i++){
            if(cur==a[i]){
                cnt++;
            }else{
                s.push_back(cnt+'0');
                s.push_back(a[i-1]);
                cnt=1;
                cur=a[i];
            }
        }
        s.push_back(cnt+'0');
        s.push_back(a[a.size()-1]);
        return s;
    }
};