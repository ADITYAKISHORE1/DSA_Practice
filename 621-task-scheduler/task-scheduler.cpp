class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto& c : tasks) {
            freq[c - 'A']++;
        }
        sort(freq.rbegin(), freq.rend());
        int spaces = n * (freq[0] - 1);
        for (int i = 1; i < 26; i++) {
            spaces -= min(freq[0] - 1, freq[i]);
        }
        spaces=max(0,spaces);
        return tasks.size() + spaces;
    }
};