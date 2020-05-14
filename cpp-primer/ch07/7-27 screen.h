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

    Screen & move(pos r, pos c) {
        cursor = r*width+c;
        return *this;
    }

    Screen & set(char ch) {
        contents[cursor] = ch;
        return *this;
    }

    Screen & set(pos r, pos c, char ch) {
        contents[r*width+c] = ch;
        return *this;
    }

    Screen & display(ostream &os) {
        do_display(os);
        return *this;
    }

private:
    void do_display(ostream &os) {
        for (pos i=0; i<width; ++i) {
            for (pos j=0; j<height; ++j)
                os << contents[i*width+j];
            os << endl;
        }
    }

    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};