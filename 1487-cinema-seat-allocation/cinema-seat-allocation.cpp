class Solution {
public:
    int maxNumberOfFamilies(int m, vector<vector<int>>& reservedSeats) {
        int n = reservedSeats.size();
        sort(reservedSeats.begin(), reservedSeats.end());
        int cnt = (reservedSeats[0][0]-1)*2+(m-reservedSeats.back()[0])*2;
        vector<int> v(3, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0 && reservedSeats[i][0] != reservedSeats[i - 1][0])
                cnt += (reservedSeats[i][0] - reservedSeats[i - 1][0] - 1) * 2;

            if (reservedSeats[i][1] >= 2 and reservedSeats[i][1] <= 5)
                v[0] = 1;
            if (reservedSeats[i][1] >= 4 and reservedSeats[i][1] <= 7)
                v[1] = 1;
            if (reservedSeats[i][1] >= 6 and reservedSeats[i][1] <= 9)
                v[2] = 1;

            if (i == n - 1 or reservedSeats[i][0] != reservedSeats[i + 1][0]) {
                if (v[0] == 0 or v[2] == 0)
                    cnt += (v[0] == 0) + (v[2] == 0);
                else
                    cnt += (v[1] == 0);
                v[0] = v[1] = v[2] = 0;
            }
        }
        return cnt;
    }
};