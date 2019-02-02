#include <stdio.h>

using namespace std;

int main() {
    int a, b;
    // FILE * fp = fopen("1000.txt", "r");
    // while (fscanf(fp, "%d %d", &a, &b) != EOF){
    while (scanf("%d %d", &a, &b) != EOF){
        printf("%d\n", a+b);
    }

    return 0;
}