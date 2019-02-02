// HDU1003 Max Sum 最大子序列和的问题【四种算法分析+实现】
//   https://blog.csdn.net/chang_mu/article/details/26157759

#include <stdio.h>
#include <vector>

using namespace std;

void findMaxSum(vector<int> &seq) {
    int max_sum, this_sum;
    int head, tail, head_tmp;

    head = tail = head_tmp = 0;
    // If we know the lower bound of the numbers,
    //   we could reduce the following block
    //   into the later `for loop` block
    this_sum = max_sum = seq[0];
    if (this_sum < 0) {
        this_sum = 0;
        head_tmp = 1;
    }

    for (int i=1; i<seq.size(); ++i) {
        this_sum += seq[i];

        if (this_sum > max_sum) {
            // Here max_sum could be < 0
            max_sum = this_sum;
            head = head_tmp; // Important!
            tail = i;
        }
        // ^v These two blocks should not be swapped!
        if (this_sum < 0){
            this_sum = 0;
            head_tmp = i+1;
        }
    }

    printf("%d %d %d\n", max_sum, head+1, tail+1);
}

int main() {
    int case_size, line_size;

    // FILE * fp = fopen("1003.txt", "r");
    // fscanf(fp, "%d", &case_size);
    scanf("%d", &case_size);

    for (int i=0; i<case_size; ++i) {
        // fscanf(fp, "%d", &line_size);
        scanf("%d", &line_size);
        vector<int> seq(line_size);
        for (int j=0; j<line_size; ++j) {
            // fscanf(fp, "%d", &seq[j]);
            scanf("%d", &seq[j]);
        }
        printf("Case %d:\n", i+1);
        findMaxSum(seq);
        if (i<case_size-1){
            printf("\n");
        }
    }
    return 0;
}