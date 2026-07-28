class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> mpp;
        for (char& c : t) {
            mpp[c]++;
        }
        int head = 0, win = n;
        int start = 0, cnt = m;
        for (int end = 0; end < n; end++) {
            if (mpp[s[end]] > 0) {
                cnt--;
            }
            mpp[s[end]]--;
            while(cnt==0){
                while(start<=end){
                    if(!mpp.count(s[start])) start++;
                    else if(mpp[s[start]]<0){
                        mpp[s[start]]++;
                        start++;
                    }else break;
                }
                if(end-start<win){
                    head=start;
                    win=end-start;
                }
                cnt++;
                mpp[s[start]]++;
                start++;
            }
            
        }
        if (win == n)
            return "";
        return s.substr(head, win + 1);
    }
};