class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            for(int c=1;c<s.size()-1;c++){
                if(s[c]>s[c-1] and s[c]>s[c+1]) cnt++;
                else if(s[c]<s[c-1] and s[c]<s[c+1]) cnt++;
            }
        }
        return cnt;
    }
};