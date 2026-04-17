class MedianFinder {
    priority_queue<int> pq;
    stack<int> st;

   public:
    MedianFinder() {}

    void addNum(int num) { pq.push(num); }

    double findMedian() {
        int n = pq.size();
        int m = n / 2 + 1;
        while (pq.size() > m) {
            st.push(pq.top());
            pq.pop();
        }
        double a, b;
        if (n % 2 == 0) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.push(a);
            a = (a + b) / 2.0;
        } else
            a = pq.top();
        while (!st.empty()) {
            pq.push(st.top());
            st.pop();
        }
        return a;
    }
};
