class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        if (n <= 1)
            return n;

        int l = 0, r = 0;
        int maxFruit = 0;

        int f1 = -1, f2 = -1;
        int last1 = -1, last2 = -1;

        while (r < n) {

            if (f1 == -1) {
                f1 = fruits[r];
                last1 = r;
                r++;
            }

            else if (f2 == -1) {
                if (fruits[r] == f1) {
                    last1 = r;
                } else {
                    f2 = fruits[r];
                    last2 = r;
                }
                r++;
            }

            else if (fruits[r] == f1) {
                last1 = r;
                r++;
            }

            else if (fruits[r] == f2) {
                last2 = r;
                r++;
            }

            else {
                maxFruit = max(maxFruit, r - l);
                if (last1 < last2) {
                    l = last1 + 1;

                    f1 = f2;
                    last1 = last2;

                    f2 = fruits[r];
                    last2 = r;
                }
                else {
                    l = last2 + 1;

                    f2 = f1;
                    last2 = last1;

                    f1 = fruits[r];
                    last1 = r;
                }

                r++;
            }
        }

        maxFruit = max(maxFruit, r - l);

        return maxFruit;
    }
};