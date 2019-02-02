#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

// This variable should declare outside main()
int mat[100100][11];

int main() {
    int n;
    int x, t;
    int t_max = 0;

    // FILE * fp = fopen("1176.txt", "r");
    // fscanf(fp, "%d", &n);
    scanf("%d", &n);

    while(n != 0){
        memset(mat, 0, sizeof(mat));
        for (int i=0; i<n; ++i) {
            // fscanf(fp, "%d %d", &x, &t);
            scanf("%d %d", &x, &t);
            mat[t][x]++;
            if (t>t_max){
                t_max = t;
            }
        }

        for (int i=t_max-1; i>=0; --i) {
            for (int j=0; j<=10; ++j) {
                if (j>0 && j<10){
                    mat[i][j] += max(max(mat[i+1][j-1], mat[i+1][j]), mat[i+1][j+1]);
                } else if (j==0){
                    mat[i][j] += max(mat[i+1][j], mat[i+1][j+1]);
                } else if(j==10){
                    mat[i][j] += max(mat[i+1][j-1], mat[i+1][j]);
                }
            }
        }
        printf("%d\n", mat[0][5]);

        // fscanf(fp, "%d", &n);
        scanf("%d", &n);
    }

    return 0;
}