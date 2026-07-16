class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int size = m + n;
        int i = 0, j = 0, k = 0;
        int ele1 = -1, ele2 = -1;
        while (i < m and j < n) {
            if (nums1[i] < nums2[j]) {
                if (k == size / 2 - 1) {
                    ele1 = nums1[i];
                } else if (k == size / 2) {
                    ele2 = nums1[i];
                }
                i++;
            } else {
                if (k == size / 2 - 1) {
                    ele1 = nums2[j];
                } else if (k == size / 2) {
                    ele2 = nums2[j];
                }
                j++;
            }
            k++;
        }
        while (i < m) {
            if (k == size / 2 - 1) {
                ele1 = nums1[i];
            } else if (k == size / 2) {
                ele2 = nums1[i];
            }
            i++;
            k++;
        }
        while (j < n) {
            if (k == size / 2 - 1) {
                ele1 = nums2[j];
            } else if (k == size / 2) {
                ele2 = nums2[j];
            }
            j++;
            k++;
        }
        if(size%2==0) return (double)(ele1+ele2)/2.0;
        return ele2;
    }
};