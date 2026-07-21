class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool isCommented = false;
        string left;
        for (auto& s : source) {
            while (true) {
                if (isCommented) {
                    auto pos = s.find("*/");
                    if (pos == string::npos) {
                        s = "";
                        break;
                    }
                    s.erase(0, pos + 2);
                    s = left + s;
                    left = "";
                    isCommented = false;
                }
                auto pos = s.find("//");
                auto pos1 = s.find("/*");
                if (pos != string::npos and
                    (pos1 == string::npos || pos < pos1)) {
                    s.erase(pos);
                    break;
                }
                if (pos1 == string::npos) {
                    break;
                }
                int pos2 = s.find("*/", pos1 + 2);
                if (pos2 == string::npos) {
                    s.erase(pos1);
                    left=s;
                    isCommented=true;
                    break;
                }
                s.erase(pos1,pos2-pos1+2);
            }
            if(!isCommented and !s.empty()){
                ans.push_back(s);
            }
        }
        return ans;
    }
};