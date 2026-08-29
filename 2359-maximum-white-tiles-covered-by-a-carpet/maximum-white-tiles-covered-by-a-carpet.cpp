class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n=tiles.size();
        int l=0,r=0;
        sort(tiles.begin(),tiles.end());
        int maxCoveredTiles=0;
        int tilesCovered=0;
        for(l=0;l<n;l++){
            int carpetEnd=tiles[l][0]+carpetLen-1;
            while(r<n and tiles[r][1]<=carpetEnd){
                tilesCovered+=tiles[r][1]-tiles[r][0]+1;
                r++;
            }
            int partial=0;
            if(r<n and tiles[r][0]<=carpetEnd){
                partial=carpetEnd-tiles[r][0]+1;
            }
            maxCoveredTiles=max(maxCoveredTiles,tilesCovered+partial);
            tilesCovered-=tiles[l][1]-tiles[l][0]+1;
        }
        return maxCoveredTiles;
    }
};