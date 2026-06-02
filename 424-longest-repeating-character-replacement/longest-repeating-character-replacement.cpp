class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq = 0;
        int maxwin = 0;
        int l = 0;
        vector<int> freq(26, 0);
        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq,freq[s[r]-'A']);
            if ((r - l + 1) - maxfreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            maxwin = max(maxwin, r - l + 1);
        }
        return maxwin;
    }
};