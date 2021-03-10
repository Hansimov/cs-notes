class Flip {
public:
    vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) {
        // A: initial board
        // f: flap positions
        int r,c,i,j;
        vector<vector<int>> d = {{0,-1},{0,1},{-1,0},{1,0}};
        for (auto const v: f) {
            r=v[0]-1, c=v[1]-1;
            for (auto const pos: d) {
                int i = r+pos[0], j = c+pos[1];
                if (i>=0 && i<=3 && j>=0 && j<=3)
                    A[i][j] = (A[i][j]==0) ? 1 : 0;
            }
        }
        return A;
    }
};