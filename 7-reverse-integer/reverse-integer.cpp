class Solution {
public:
    int reverse(int x) {
        int p=(x<0);
        long long y =llabs(x);
        string s=to_string(y);
        std::reverse(s.begin(),s.end());
        y=stoll(s);
        if(p) y=-y;
        if(y < INT_MIN || y > INT_MAX) return 0;
        return y;
    }
};