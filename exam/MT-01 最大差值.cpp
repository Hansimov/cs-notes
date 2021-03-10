class LongestDistance {
public:
    int getDis(vector<int> A, int n) {
        int res = 0;
        int min_val = A[0];
        for (int i=1; i<A.size(); ++i) {
            min_val = min(min_val, A[i]);
            res = max(res, A[i]-min_val);
        }
        return res;
    }
};