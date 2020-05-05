#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    char ch;
    int vowel_cnt = 0;
    int space_cnt = 0;
    while (cin >> noskipws >> ch) {
        switch (ch) {
            case 'a': case 'A':
            case 'e': case 'E':
            case 'i': case 'I':
            case 'o': case 'O':
            case 'u': case 'U':
                ++vowel_cnt;
                break;
            case ' ': case '\t': case '\n':// case '\r':
                ++space_cnt;
                break;
            default:
                break;
        }
    }

    cout << "vewel count: " << vowel_cnt << endl;
    cout << "space count: " << space_cnt << endl;

    return 0;
}