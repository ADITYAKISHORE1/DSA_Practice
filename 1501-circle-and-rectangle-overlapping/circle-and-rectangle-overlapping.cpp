class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int clampX=max(x1,min(x2,xCenter));
        int clampY=max(y1,min(y2,yCenter));
        int dx=xCenter-clampX;
        int dy=yCenter-clampY;
        return dx*dx+dy*dy<=radius*radius;
    }
};