class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0) return false; 
        unordered_map<int,pair<int,int>> hash;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                hash[grid[i][j]]={i,j};
            }
        }
        for(int i=0;i<n*n-1;i++){
            auto [x1,y1]=hash[i];
            auto [x2,y2]=hash[i+1];
            int d1=abs(x1-x2);
            int d2=abs(y1-y2);
            // cout<<d1<<" "<<d2<<endl;
            if((d1==1 and d2==2) or (d1==2 and d2==1)) continue;
            return false;
        }
        return true;
    }
};