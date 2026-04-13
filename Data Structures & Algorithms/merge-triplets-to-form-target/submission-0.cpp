class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a=0,b=0,c=0;
        for(auto i:triplets){
            if(i[0]>target[0] or i[1]>target[1] or i[2]>target[2]) continue;
            a=max(a,i[0]);
            b=max(b,i[1]);
            c=max(c,i[2]);
        }
        return (a==target[0] and b==target[1] and c==target[2]);
    }
};
