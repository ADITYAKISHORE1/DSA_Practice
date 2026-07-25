class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string a;
        while (ss >> a) {
        }
        return a.size();
    }
};