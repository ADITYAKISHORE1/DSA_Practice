class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> first(32, -2);
        int h = 0;
        int ans=0;
        first[0]=-1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                h ^= 1;
            else if (s[i] == 'e')
                h ^= (1 << 1);
            else if (s[i] == 'i')
                h ^= (1 << 2);
            else if (s[i] == 'o')
                h ^= (1 << 3);
            else if (s[i] == 'u')
                h ^= (1 << 4);

            if(first[h]==-2) first[h]=i;
            else ans=max(ans,i-first[h]);
        }
        return ans;
    }
};