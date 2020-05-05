#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string prev_word, word, most_word;
    int cnt = 0, max_cnt = 0;
    while (cin >> word) {
        if (word == prev_word) {
            cnt += 1;
            if (cnt>max_cnt) {
                most_word = word;
                max_cnt = cnt;
            }
        } else {
            cnt = 1;
        }
        prev_word = word;
    }

    cout << most_word << " " << max_cnt;


    return 0;
}