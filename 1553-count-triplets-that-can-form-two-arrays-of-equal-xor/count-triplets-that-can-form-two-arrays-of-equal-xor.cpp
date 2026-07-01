class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int d = 0;
            for (int j = i; j < n; j++) {
                d ^= arr[j];
                if (d == 0)
                    cnt += j - i;
            }
        }
        return cnt;
    }
};