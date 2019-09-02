### Commonly used libraries

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <limits.h>

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

### In : int
### Out: int

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

string filename = "0070.txt";
const auto& myFunc = climbStairs;

int main() {
    string sin;
    int n, r;
    vector<int> vn, vr;

    ifstream fp;
    fp.open(filename);

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
        int res = myFunc(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```

### In : int x 2
### Out: bool

```
r   n   t
```

`0464.txt`

```py
0   10  11
0   5   100
0   20  100
1   20  20
```

`0464.cpp`:

```cpp
bool canIWin(int maxChoosableInteger, int desiredTotal) {
    return false;
}

string filename = "0464.txt";
const auto& myFunc = canIWin;

int main() {
    string sin;
    int r, n, t;
    vector<int> vr, vn, vt;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> r >> n >> t;
        vr.push_back(r);
        vn.push_back(n);
        vt.push_back(t);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        bool res = myFunc(vn[i],vt[i]);
        bool is_correct = (int)res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```


### In : vector<int>
### Out: int

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

string filename = "0053.txt";
const auto& myFunc = maxSubArray;

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    int d;
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
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vs.size(); ++i) {
        int res = myFunc(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```

### In : vector<int> + int
### Out: int

```
data
n r
```

`0322.txt`:

```py
1 2 5
11 3
```

`0322.cpp`:

```cpp
int coinChange(vector<int>& coins, int amount) {
    return 0;
}

string filename = "0322.txt";
const auto& myFunc = coinChange;

int main() {
    string vin, nrin;
    vector<vector<int>> vv;
    vector<int> vn;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, vin, '\n')) {
        stringstream sv(vin);

        vector<int> vvi = {};
        while (sv >> d) {
            vvi.push_back(d);
        }
        vv.push_back(vvi);

        getline(fp, nrin, '\n');
        stringstream snr(nrin);
        snr >> d;
        vn.push_back(d);
        snr >> d;
        vr.push_back(d);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        int res = myFunc(vv[i],vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```

### In : vector<int> x 2
### Out: double

```
a1 a2 a3 ...
b1 b2 b3 ...
r(double)
```

`0004.txt`:

```py
1 2 3 6 7 10
2 3 4 7 9
4.0
```

`0004.cpp`:


```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    return 0.0;
}

string filename = "0004.txt";
const auto& myFunc = findMedianSortedArrays;

int main() {
    string sin1, sin2, rin;
    vector<vector<int>> vv1, vv2;
    vector<double> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, sin1, '\n')) {
        getline(fp,sin2,'\n');

        stringstream ss1(sin1);
        stringstream ss2(sin2);

        vector<int> vvi1 = {};
        vector<int> vvi2 = {};

        while (ss1 >> d) vvi1.push_back(d);
        while (ss2 >> d) vvi2.push_back(d);

        vv1.push_back(vvi1);
        vv2.push_back(vvi2);

        getline(fp, rin, '\n');
        stringstream sr(rin);
        double d;
        sr >> d;
        vr.push_back(d);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        double res = myFunc(vv1[i],vv2[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%.1f\t%.1f\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```

### In : vector<int> x 2 + int
### Out: vector<int>


```
vector1
vector2
num
r(vector)
```

`0312.txt`:

```py
3 4 6 5
9 1 2 5 8 3
5
9 8 1 6 5 3
6 7
6 0 4
5
6 7 6 0 4
```

`0312.cpp`:

```cpp
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> dp(k,0);
    return dp;
}

string filename = "0321.txt";
const auto& myFunc = maxNumber;

int main() {
    string sin1, sin2, nin, rin;
    vector<vector<int>> vv1,vv2;
    vector<int> vn;
    vector<vector<int>> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, sin1, '\n')) {
        getline(fp, sin2, '\n');
        getline(fp, nin, '\n');
        getline(fp, rin, '\n');

        stringstream ss1(sin1);
        stringstream ss2(sin2);
        stringstream sr(rin);

        vector<int> vvi1 = {};
        vector<int> vvi2 = {};
        vector<int> vri = {};

        while (ss1 >> d) vvi1.push_back(d);
        while (ss2 >> d) vvi2.push_back(d);
        while (sr >> d) vri.push_back(d);
        vv1.push_back(vvi1);
        vv2.push_back(vvi2);
        vr.push_back(vri);

        vn.push_back(stoi(nin.c_str(),NULL,10));
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        vector<int> res = myFunc(vv1[i],vv2[i],vn[i]);
        bool is_correct = res==vr[i];
        for (int j=0; j<vr[i].size(); ++j) {
            cout << "-" << vr[i][j];
        };
        cout << endl;
        for (int j=0; j<res.size(); ++j) {
            cout << "-" << res[j];
        };
        cout << endl;

        printf("%d\t%d\n", is_correct, 4*i+1);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```

### In : int
### Out: vector<int>


```
num
r(vector)
```

`0388.txt`:

```py
2
0 1 1
5
0 1 1 2 1 2
```

`0388.cpp`:

```cpp
vector<int> countBits(int num) {
    return {};
}

string filename = "0338.txt";
const auto& myFunc = countBits;

int main() {
    string nin, rin;
    vector<int> vn;
    vector<vector<int>> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, nin, '\n')) {
        getline(fp, rin, '\n');

        stringstream sr(rin);

        vn.push_back(stoi(nin.c_str(),NULL,10));

        vector<int> vri = {};
        while (sr >> d) vri.push_back(d);
        vr.push_back(vri);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        vector<int> res = myFunc(vn[i]);
        bool is_correct = res==vr[i];
        for (int j=0; j<vr[i].size(); ++j) {
            cout << "-" << vr[i][j];
        };
        cout << endl;
        for (int j=0; j<res.size(); ++j) {
            cout << "-" << res[j];
        };
        cout << endl;

        printf("%d\t%d\n", is_correct, 4*i+1);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```

### In : one-line int pairs (vector<vector<int>>)
### Out: int

```
n11 n12  n21 n22  n31 n32  ...
r(int)
```

`0354.txt`:

```py
5 4  6 4  6 7  2 3
3
4 4  9 4  2 8  1 6  4 7  9 10  5 1  3 9  7 3
4
```

`0354.cpp`:

```cpp
int maxEnvelopes(vector<vector<int>>& envelopes) {
    return 0;
}

string filename = "0354.txt";
const auto& myFunc = maxEnvelopes;

int main() {
    string vin, rin;
    vector<vector<vector<int>>> vv;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, vin, '\n')) {
        stringstream sv(vin);

        vector<int> vvt = {};
        while (sv>>d) {
            vvt.push_back(d);
        }

        vector<vector<int>> vvi = {};
        for (int i=0; i<vvt.size()/2; ++i) {
            vvi.push_back({vvt[2*i],vvt[2*i+1]});
        }
        vv.push_back(vvi);

        getline(fp, rin, '\n');
        vr.push_back(stoi(rin.c_str(),NULL,10));
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        int res = myFunc(vv[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```

### In : vector<vector<int>> (m x n)
### Out: int

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

string filename = "0064.txt";
const auto& myFunc = minPathSum;

int main() {
    string sin;
    int row, col, rr, ele;
    vector<vector<vector<int>>> vg={};
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

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
                ss >> ele;
                vg.back()[i].push_back(ele);
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
        int res = myFunc(vg[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += vg[i].size()+1;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```


### In : vector<vector<char>> (m x n)
### Out: int

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

### In : string
### Out: int

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

string filename = "0091.txt";
const auto& myFunc = numDecodings;

int main() {
    string sin, rin, s1;
    int r;
    vector<int> vr;
    vector<string> vs1;

    ifstream fp;
    fp.open(filename);

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
        int res = myFunc(vs1[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 2;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```


### In : string x 2
### Out: int

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

string filename = "0072.txt";
const auto& myFunc = minDistance;

int main() {
    string sin, rin, s1, s2;
    int r;
    vector<int> vr;
    vector<string> vs1, vs2;

    ifstream fp;
    fp.open(filename);

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
        int res = myFunc(vs1[i], vs2[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```

### In : int + string x 2
### Out: bool

```
r(int) str1 str2
```

`0392.txt`:

```py
1 abc ahbgdc
0 axc ahbgdc
```

`0392.cpp`:

```cpp
bool isSubsequence(string s, string t) {
    return false;
}

string filename = "0392.txt";
const auto& myFunc = isSubsequence;

int main() {
    string sin,s1,s2;
    int r;
    vector<int> vr;
    vector<string> vs1, vs2;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> r >> s1 >> s2;
        vr.push_back(r);
        vs1.push_back(s1);
        vs2.push_back(s2);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = myFunc(vs1[i], vs2[i]);
        bool is_correct = ((int)res==vr[i]);
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```


### In : (string + int) x 2
### Out: int

```
s1  n1  s2  n2
r(int)
```

`0466.txt`:

```py
acb     4   ab  2
2
acbacb  5   ac  2
5
```

`0466.cpp`:


```cpp
int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    return 0;
}

string filename = "0466.txt";
const auto& myFunc = getMaxRepetitions;

int main() {
    string sin, rin, s1, s2;
    int n1, n2, r;
    vector<int> vr;
    vector<string> vs1, vs2;
    vector<int> vn1, vn2;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> s1 >> n1 >> s2 >> n2;
        vs1.push_back(s1);
        vs2.push_back(s2);
        vn1.push_back(n1);
        vn2.push_back(n2);

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
        int res = myFunc(vs1[i], vn1[i], vs2[i], vn2[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```
### In : multi-line hybrid int & strings
### Out: bool

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

string filename = "0139.txt";
const auto& myFunc = wordBreak;

int main() {
    string sin, rin, s, word;
    int r;
    vector<string> vs;
    vector<vector<string>> vw;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

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
        bool res = myFunc(vs[i], vw[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}
```