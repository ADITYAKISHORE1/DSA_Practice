class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        stack<int> openBrackets,star;
        for(int i=0;i<n;i++){
            if(s[i]=='(') openBrackets.push(i);
            else if(s[i]=='*') star.push(i);
            else{
                if(!openBrackets.empty()) openBrackets.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        while(!openBrackets.empty()){
            if(star.empty()) return false;
            if(star.top()<openBrackets.top()) return false;
            openBrackets.pop();
            star.pop();
        }
        return true;
    }
};
