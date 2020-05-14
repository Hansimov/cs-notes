#include <iostream>
#include <string>

using namespace std;

struct Screen {
    using pos = string::size_type;

    Screen() = default;
    Screen(pos h, pos w)
        : height(h), width(w), contents(h*w, ' ') {}

    Screen(pos h, pos w, char c)
        : height(h), width(w), contents(h*w, c) {}

    char get() const {
        return contents[cursor];
    }
    char get(pos r, pos c) const {
        return contents[r*width+c];
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};