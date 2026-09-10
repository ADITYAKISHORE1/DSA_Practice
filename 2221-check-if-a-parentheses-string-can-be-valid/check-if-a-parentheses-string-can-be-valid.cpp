class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2==1) return false;
        int balance=0;
        for(int i=0;i<n;i++){ // checking for "can we avoid excess ) "
            if(s[i]=='(' || locked[i]=='0'){
                balance++;
            }else balance--;
            if(balance<0) return false;
        }
        // at last balance will be always even bcz n will be even and add or substract of two even or two odd is always even.
        balance=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')' || locked[i]=='0'){ // checking for "can we avoid excess ( "
                balance++;
            }else balance--;
            if(balance<0) return false;
        }
        return true;
    }
};