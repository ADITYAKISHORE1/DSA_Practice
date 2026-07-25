class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string a,ans;
        while(ss>>a){
            ans= a+" "+ans;
        }
        ans.pop_back();
        return ans;
    }
};