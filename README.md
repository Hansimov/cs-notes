### Commonly used libraries

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
```

### Speedup data IO

```cpp
static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
```

## Input processing

### Input form: int

```
n r(int)
```

`0070.txt`

```py
0 0
1 1
2 2
3 3
4 5
14 610
```

`0070.cpp`:

```cpp
...

int climbStairs(int n) {

    return 0;
}

int main() {
    string sin;
    int n, r;
    vector<int> vn, vr;

    ifstream fp;
    fp.open("0070.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> n >> r;
        vn.push_back(n);
        vr.push_back(r);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = climbStairs(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}
```


### Input form: ints

```
data
r(int)
```

`0053.txt`:

```py
-2 1 -3 4 -1 2 1 -5 4
6
1 2 3
6
-1 1 2 3
6
-1 -1 -2 -3 -5
-1
-4 -1 -2 -3 -5
-1
```

`0053.cpp`:

```cpp
...

int maxSubArray(vector<int>& nums) {

    return 0;
}

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open("0053.txt");

    int d;
    int c=0;
    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
        stringstream ss(sin);

        vector<int> vni = {};
        while (ss >> d) {
            vni.push_back(d);
            // printf("%d ", d);
        }
        vn.push_back(vni);

        getline(fp, rin, '\n');
        vr.push_back(stoi(rin.c_str(),NULL,10));
        // ++c;printf("==%d==\n", c);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vs.size(); ++i) {
        int res = maxSubArray(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}
```


### Input form: m x n int matrix

```
m n r(int)
data
```

`0064.txt`:

```py
3 3 7
1 3 1
1 5 1
4 2 1
4 4 7
1 2 1 2
1 1 4 3
2 1 1 1
1 2 2 1
```


`0064.cpp`:

```cpp
...

int minPathSum(vector<vector<int>>& grid) {

    return 0;
}

int main() {
    string sin;
    int rr, row, col, weight;
    vector<vector<vector<int>>> vg={};
    vector<int> vr;

    ifstream fp;
    fp.open("0064.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> row >> col >> rr;
        vr.push_back(rr);
        vg.push_back({});
        for (int i=0; i<row; ++i) {
            getline(fp, sin, '\n');
            stringstream ss(sin);
            vg.back().push_back({});
            for (int j=0; j<col; ++j) {
                ss >> weight;
                vg.back()[i].push_back(weight);
            }
        }
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = minPathSum(vg[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += vg[i].size()+1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
```


### Input form: m x n char matrix

```
m n r(int)
data
```

`0085.txt`:

```py
4 5 6
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
5 6 4
1 1 1 0 1 1
1 0 1 1 1 0
1 1 1 1 0 1
1 0 1 0 1 1
1 1 0 1 1 0
```

`0085.cpp` (Similar to `0064.cpp`):

```cpp
...

int maximalRectangle(vector<vector<char>>& matrix) {

...

        vg.back()[i].push_back('0'+state);

...
```

### Input form: string

```
str
r(int)
```

`0091.txt`:

```py
12
2
226
3
12123161226
80
```

`0091.cpp`:

```cpp
...

int numDecodings(string s) {
    return s.size();
}

int main() {
    string sin, rin, s1;
    int r;
    vector<int> vr;
    vector<string> vs1;

    ifstream fp;
    fp.open("0091.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> s1;
        vs1.push_back(s1);
        getline(fp, rin, '\n');
        stringstream sr(rin);
        sr >> r;
        vr.push_back(r);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = numDecodings(vs1[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 2;
    }

    return 0;
}
```


### Input form: strings

```
str1 str2
r(int)
```

`0072.txt`:

```py
horse ros
3
intention execution
5
hello olleh
4
```

`0072.cpp`:

```cpp
...

int minDistance(string word1, string word2) {

    return 0;
}

int main() {
    string sin, rin, s1, s2;
    int r;
    vector<int> vr;
    vector<string> vs1, vs2;

    ifstream fp;
    fp.open("0072.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> s1 >> s2;
        vs1.push_back(s1);
        vs2.push_back(s2);
        getline(fp, rin, '\n');
        stringstream sr(rin);
        sr >> r;
        vr.push_back(r);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = minDistance(vs1[i], vs2[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}
```


### Input form: multi-line hybrid int & strings

```
str
r(int) str1 str2 ...
```

`0139.txt`:

```py
leetcode
1 leet code
applepenapple
1 apple pen
catsandog
0 cats dog sand and cat
aaaaa
0 aa aaaa
```

`0139.cpp`:


```cpp
...

bool wordBreak(string s, vector<string>& wordDict) {

    return false;
}

int main() {
    string sin, rin, s, word;
    int r;
    vector<string> vs;
    vector<vector<string>> vw;
    vector<int> vr;

    ifstream fp;
    fp.open("0139.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> s;
        vs.push_back(s);
        getline(fp, rin, '\n');
        stringstream sr(rin);
        sr >> r;
        vr.push_back(r==1);
        vector<string> vwi = {};
        while (sr >> word) {
            vwi.push_back(word);
        }
        vw.push_back(vwi);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        bool res = wordBreak(vs[i], vw[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}
```