class Solution {
    vector<string> ans;
    void f(int idx,int left,int hour,int minute){
        if(hour>11 or minute>59) return;
        if(left==0){
            string t=to_string(hour)+":";
            string m=to_string(minute);
            if(m.size()==1) t+="0";
            t+=m;
            ans.push_back(t);
            return;
        }

        for(int i=idx;i<10;i++){
            if(i<4){
                f(i+1,left-1,hour|(1<<i),minute);
            }else{
                f(i+1,left-1,hour,minute|(1<<(i-4)));
            }
        }
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        f(0,turnedOn,0,0);
        return ans;
    }
};