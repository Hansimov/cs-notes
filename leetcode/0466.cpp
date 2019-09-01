/*
= Count The Repetitions - LeetCode Articles 
    https://leetcode.com/articles/count-the-repetitions/
= 【Leetcode】466. Count The Repetitions 统计重复个数 - lemonmillie的博客 - CSDN博客 
    https://blog.csdn.net/lemonmillie/article/details/86701249
= Accepted 8ms Java solution with explanation - LeetCode Discuss 
    https://leetcode.com/problems/count-the-repetitions/discuss/95426/Accepted-8ms-Java-solution-with-explanation
= C++ solution inspired by @70664914 with organized explanation - LeetCode Discuss 
    https://leetcode.com/problems/count-the-repetitions/discuss/95398/C%2B%2B-solution-inspired-by-%4070664914-with-organized-explanation
*/

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

int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    
    string t1, t2;
    for (int i=0; i<n1; ++i) t1 += s1;
    for (int i=0; i<n2; ++i) t2 += s2;



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