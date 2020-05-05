#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string prev_word, word;
    while (cin >> word) {
        if (prev_word == word) {
            cout << word << endl;
            return 0;
        }
        prev_word = word;
    }

    cout << "No same words find!" << endl;

    return 0;
}