class Solution {
    vector<string> f(int prev,int n,int k){
        if(k<0 or n<0) return {};
        if(n==0){
            if(prev) return {"0"};
            else return {"1","0"};
        }
            vector<string> st=f(0,n-1,k);
        
            for(auto& s:st){
                s=s+"0";
            }
        if(!prev){
            vector<string> st1=f(1,n-1,k-n);
            for(auto &s:st1){
                s=s+"1";
                st.push_back(s);
            }
        }
        return st;
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> st1=f(0,n-1,k);
        return st1;
    }
};