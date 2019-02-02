// HDU1003 Max Sum 最大子序列和的问题【四种算法分析+实现】
//   https://blog.csdn.net/chang_mu/article/details/26157759

#include <stdio.h>
 
int main(){
    int t, n, maxLeft, maxRight, maxSum, temp;
    int thisLeft, thisSum;

    FILE * fp = fopen("1003.txt", "r");
    fscanf(fp, "%d", &t);
    // scanf("%d", &t);
    for(int id = 1; id <= t; ++id){
        // scanf("%d", &n);
        // scanf("%d", &maxSum);
        fscanf(fp,"%d", &n);
        fscanf(fp,"%d", &maxSum);

        thisLeft = maxLeft = maxRight =  0;
        thisSum = maxSum;
        if(thisSum < 0){ thisSum = 0; thisLeft = 1; }
        for(int i = 1; i < n; ++i){
            // scanf("%d", &temp);
            fscanf(fp, "%d", &temp);
            thisSum += temp;
            if(thisSum > maxSum){
                maxSum = thisSum;
                maxLeft = thisLeft;
                maxRight = i;
            }
            if(thisSum < 0){
                thisLeft = i + 1;
                thisSum = 0;
            }
        }
        printf("Case %d:\n%d %d %d\n", id, maxSum, maxLeft + 1, maxRight + 1);
        if(id != t) printf("\n");
    }
    return 0;
}
