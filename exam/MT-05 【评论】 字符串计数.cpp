/*
2
首先要搞清楚字典序的意思：即从两个字符串的下标为 0 开始进行对比，字典序是从左往右进行对比的。
例如 ab，abc 这样两者之间的字符串个数为 aba、abb，而 ab、bb 两者之间的字符串个数为：ac、ad、ae…az、ba 这 26 个，所以高位的字符串个数要是 26 的 i 次幂。
其次，要理解题目的 “长度在 len1 到 len2 的字符串的个数”，指的是长度在 len1 的字符串个数、长度在 len1+1 的字符串个数。。。长度为 len2 的字符串个数。
例 abcde、acede 这两个字符串，长度为 1 到 4 表示的是长度为 1 的时候两个字符 a、a 之间的个数，长度为 2 的时候两个字符 ab、ac 之间的个数，长度为 3 的时候 abc、ace 两个字符串之间的个数，长度为 4：abcd、aced 的个数。
所以计算的时候应该以长度作为变量遍历 len1 到 len2 之间的字符串个数，最后相加。

*/

/*
链接：https://www.nowcoder.com/questionTerminal/f72adfe389b84da7a4986bde2a886ec3
来源：牛客网

O(len2) 的算法， 建一个 dp 数组用来保存 s1,s2 之间长度为 i 的 String 的个数。从 len1 开始累加到 len2。
很容易看出 dp[i] = 26*dp[i-1] - s1[i-1] + s2[i-1];
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string s1, s2;
    int len1, len2;
    while (cin >> s1 >> s2 >> len1 >> len2) {
        int result = 0;
        int dp[120];
        for (int i = 1; i <= len2; i++) {
            dp[i] = (26 * (dp[i-1])) % 1000007;
            if (i <= s1.size())
                dp[i] -= (s1[i-1]-'a');
            if (i <= s2.size())
                dp[i] += (s2[i-1]-'a');
            if (i == s2.size())
                dp[i]--;
            if (i >= len1)
                result += dp[i];
        }
        cout << result % 1000007 << endl;
    }
    return 0;
}


/* 看了之前 50 多个答案，发现大部分都是错误的，根据自己对题目的理解，给出了以下思路，目前
我还没有找到 bug，欢迎牛友们检查，如有 bug，我继续修改，答题思路是对的 */

/* 首先是从之前的几个测试样例分析，其中一个为 str1 = cpqejrrgp, str2 = cpqejtrdg,
len1 = 9, len2 = 9，设所求满足情况的字符串代号为 str（str 有 35064 种）。
第一步：首先找到两个字符串相对应位置的第一个不相等的位置，即若 ab 和 ce,
第一个相对位置不相等的为值就是下标为 0 的地方 a 和 c 不一样，str1 和 str2 中第一个相对不相等
的位置是下标为 5 的地方，即 r 和 t，设下标为 k；
第二步：先求在此下标处，字符处于下标位置字符之间的情况，即 str[k]>str1[k] && str[k]<str2[k]
的情况，这个最好算，只要 k 位置大于 str1 小于 str2 对应的 k 位置，后面的任一位置可以随意取，每个
位置有 26 种，例如 str1[5] 和 str2[5] 之间共有 num1 种（‘t’-'r'-1=1 种即为 's' 这一种情况），
str[5] 为 s 的时候，后面三位可以随意取；共有 (str2[k] - str1[k] - 1)*pow(26, i - k) 种，
其中 i 为 len1 到 len2 之间的取值，这里用一个 for 循环累加；
第三步：其次再求 str[k]==str1[k] 时有多少种，此时，str[k+1] 需大于 str1[k+1],k+2 位，k+3 位...
可以随意取，接着再求 str[k]==str1[k]&&str[k+1]==str1[k+1] 的情况，需 str[k+2] 大于 str1[k+2]
，k+3 以及之后的位置随意取，以此类推，直到算到 k==len2-1 的位置为止;
第四步：最后求 str[k]==str2[k] 的情况，此时，str[k+1] 需要小于 str2[k+1],k+2，k+3 等之后的
位置随意取，接着再求 str[k]==str2[k]&&str[k+1]==str2[k+1] 的情况，需要 str[k+2] 小于 str2[k+2],
后面的位置随意取，以此类推，直到算到 k==len2-1 的位置为止；
第五步：把所有情况相加，注意还有几处边界位置需要处理，具体参考以下代码
*/
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
    string str1, str2;
    int len1, len2;
    while (cin >> str1 >> str2 >> len1 >> len2)
    {   if (str1.length() < len2)
            str1.append(len2 - str1.length(), 'a' - 1);
        if (str2.length() < len2)
            str2.append(len2 - str2.length(), 'z' + 1);
        long long sum = 0;
        int k = 0;
        // 第一步，找第一个相对位置不相等的位置下标
        while (str1[k] == str2[k])
        {k++;}
        if (str1[k] < str2[k] && len1 <= len2)
        {   // 第二步，计算 str[k]>str1[k] && str[k]<str2[k] 的情况
            for (int i = len1 - 1; i < len2; i++)
            {   if (i == k)
                {   if (k == len1 - 1 && k == len2 - 1)
                        sum += str2[k] - str1[k] - 1;
                    else
                        sum += str2[k] - str1[k];
                }
                else
                    sum += (str2[k] - str1[k] - 1) * pow(26, i - k);
            }
            k++;
            // 第三步，计算 str[k]==str1[k] 时的情况和 str[k]==str2[k] 的情况
            for (int i = len1; i <= len2; i++)
            {   for (int j = k; j < i; j++)
                    sum += ('z' - str1[j]) * pow(26, i - j - 1);
                for (int j = k; j < i; j++)
                    sum += (str2[j] - 'a') * pow(26, i - j - 1);
            }
        }
        cout << sum << endl; // 我这里没有对 1000007 取模，答案也是能过的，牛友们可自行添加}
        system("pause");
        return 0;
    }
}