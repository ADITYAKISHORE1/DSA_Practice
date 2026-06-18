class Solution {
    double mod(double a, double b) { return a - floor(a / b) * b; }

public:
    double angleClock(int hour, int minutes) {
        double m = (minutes * 6.0);
        double h = (hour * 30) % 360 + ((minutes / 60.0) * 30.0);
        return min(mod(360 - h + m, 360), mod(360 - m + h, 360));
    }
};