class Solution {
    int ham(string& s1, string& s2) {
        if (s2.size() != s1.size())
            return 3;
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            cnt += (s1[i] != s2[i]);
        }
        return cnt;
    }

public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        for (auto& s2 : queries) {
            for (auto& s1 : dictionary) {
                if (ham(s1, s2) <= 2) {
                    ans.push_back(s2);
                    break;
                }
            }
        }
        return ans;
    }
};