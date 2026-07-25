class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        while (ss >> s) {
        }
        return s.size();
    }
};