class Solution {
    vector<string> list;
    void f(int n,char c,string s){
        if(n<0){
            list.push_back(s);
            return;
        }
        if(c!='a'){
            f(n-1,'a',s+"a");
        }
        if(c!='b'){
            f(n-1,'b',s+"b");
        }
        if(c!='c'){
            f(n-1,'c',s+"c");
        }
    }
public:
    string getHappyString(int n, int k) {
        f(n-1,0,"");
        if(list.size()<k) return "";
        return list[k-1];
    }
};