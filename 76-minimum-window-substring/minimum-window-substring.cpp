class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size();
        unordered_map<char,int> mpp;
        for(auto& c:t) mpp[c]++;
        int head=0,win=m;
        int cnt=n;
        int start=0,end=0;
        while(end<m){
            if(mpp[s[end]]>0){
                cnt--;
            }
            mpp[s[end]]--;

            while(cnt==0){
                while(1){
                    if(!mpp.count(s[start])){
                        start++;
                    }else if(mpp[s[start]]<0){
                        mpp[s[start]]++;
                        start++;
                    }else break;
                }
                if(end-start<win){
                    win=end-start;
                    head=start;
                }
                cnt++;
                mpp[s[start]]++;
                start++;
            }
            end++;
        }
        if(win==m) return "";
        return s.substr(head,win+1);
    }
};