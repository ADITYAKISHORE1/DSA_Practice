class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int maxPoints=0;
        for(int i=0;i<n;i++){
            unordered_map<int,unordered_map<int,int>> mpp;
            for(int j=i+1;j<n;j++){
                int dy=points[j][1]-points[i][1];
                int dx=points[j][0]-points[i][0];

                if(dx==0){
                    dy=1;
                }else if(dy==0){
                    dx=1;
                }
                if(dx<0){
                    dy=-dy;
                    dx=-dx;
                }
                int g=gcd(abs(dy),abs(dx));
                dy/=g;
                dx/=g;
                maxPoints=max(maxPoints,++mpp[dx][dy]);
            }
        }
        return maxPoints+1;
    }
};