class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        for(string& s:strs){
            string t=s;
            sort(t.begin(),t.end());
            hash[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& i:hash){
            ans.push_back(i.second);
        }
        return ans;
    }
};