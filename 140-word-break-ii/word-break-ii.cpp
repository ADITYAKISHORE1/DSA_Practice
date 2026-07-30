class Solution {
        vector<string> ans;
        int n;
    void f(int idx,string a,string& s,vector<string>& wordDict){
        if(idx>n) return;
        if(idx==n){
            a.pop_back();
            ans.push_back(a);
            return;
        }
        for(auto& word:wordDict){
            int len=word.size();
            if(s.substr(idx,len)==word){
                f(idx+len,a+word+" ",s,wordDict);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        f(0,"",s,wordDict);
        return ans;
        
    }
};