// #include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    FILE * fp = fopen("1328.txt", "r");
    int n, d;

    fscanf(fp, "%d %d", &n, &d);
    while(n != 0){
        printf("%d %d\n", n, d);

        vector<vector<int>> p;
        for (int i=0; i<n; i++){
            int x, y;
            fscanf(fp, "%d %d", &x, &y);
            vector<int> v{x,y};
            p.push_back(v);
            printf("%d %d \n", p[i][0], p[i][1]);
        }

        // This will automatically ignore empty line.
        fscanf(fp, "%d %d", &n, &d);
    }

    printf("%d %d\n", n, d);

    return 0;
}