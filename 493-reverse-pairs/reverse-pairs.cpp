class Solution {
public:
    int reversePairs(vector<int>& arr) {
        int n = arr.size();
        vector<int> original = arr;
        // normalisation (making the vals between 1-size of array(maxm m))
        map<long long, int> mpp;
        for (auto i : arr) { // initailising arr[i] and 2* arr[i] in mpp for
                             // further ranking process
            mpp[2LL * i];
            mpp[i];
        }
        int c = 1;
        for (auto& m : mpp) { // ranking process
            m.second = c++;   // alloting rank to the vals
        }
        for (auto& i : arr)
            i = mpp[i];     // replacing vals with its rank
        int m = mpp.size(); // maxm value that can be reached
        vector<long long> bit(m + 1, 0);

        auto update = [&](int i) {
            while (i <= m) {
                bit[i] += 1;
                i += (i & -i);
            }
        };

        auto sum = [&](long long i) {
            long long s = 0;
            while (i > 0) {
                s += bit[i];
                i -= (i & -i);
            }
            return s;
        };

        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            // finding cnt of vals which is present before of idx i but greater
            // than 2* vals[i]
            cnt += sum(m) - sum(mpp[2LL * original[i]]); // using mpp to get the
                                                         // rank of 2* original
            update(arr[i]); // updating bit on rank of idx i
        }
        return cnt;
    }
};