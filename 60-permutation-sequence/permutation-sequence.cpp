class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v(n);
        iota(v.begin(),v.end(),1);
    	k--;
        while(k--){
            next_permutation(v.begin(),v.end());
        }

        string s = "";
        for(auto a : v)s += a+'0';

        return s;

    }
};