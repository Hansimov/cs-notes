class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        vector<int> res;
        int U = 0;
        int D = matrix.size()-1;
        int L = 0;
        int R = matrix[0].size()-1;
        while (true) {
            for (int j=L; j<=R; ++j)
                res.push_back(matrix[U][j]);
            if (++U > D) break;
            for (int i=U; i<=D; ++i)
                res.push_back(matrix[i][R]);
            if (--R < L) break;
            for (int j=R; j>=L; --j)
                res.push_back(matrix[D][j]);
            if (--D < U) break;
            for (int i=D; i>=U; --i)
                res.push_back(matrix[i][L]);
            if (++L > R) break;
        }
        return res;
    }
};