class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m=(minutes*6.0);
        double h=(hour*30)%360+((minutes/60.0)*30.0);
        double ans;
        if(h>=m) ans=h-m;
        else ans=m-h;
        return min({ans,360-h+m,360-m+h});
    }
};