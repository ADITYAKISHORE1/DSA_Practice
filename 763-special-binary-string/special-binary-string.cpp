class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specials;
        int sum = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += (s[i] == '1') ? 1 : -1;
            if (sum == 0) {
                string st = s.substr(start + 1, i - start);
                specials.push_back('1' + makeLargestSpecial(st) + '0');
                start = i + 1;
            }
        }
        sort(specials.begin(), specials.end(), greater<string>());
        string result;
        for (string& str : specials)
            result += str;
        return result;
    }
};

/*
A special string always starts with '1' and ends with '0'
e.g. 1001 is not special, (1100 , 1010) are special and follow above rule

also if we take +1 for '1' and -1 for '0' then prefsum will be always >=0
and when prefsum==0 then that substr will be a special string and can we swapped with consecutive specia string to get larger answer.

So for each special substring remove '1' from front and '0' from end and using recursion find the lexicographically largest resulting string
And then push it into a vector and find next special substring and do same.

atlast sort the vector in dec order and build the find result string and return
*/