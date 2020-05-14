#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Screen;

struct Window_mgr {
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    vector<Screen> screens;
};

struct Screen {
    friend void Window_mgr::clear(ScreenIndex);

    using pos = string::size_type;

    Screen() = default;
    Screen(pos h, pos w)
        : height(h), width(w), contents(h*w,' ') {}
    Screen(pos h, pos w, char ch)
        : height(h), width(w), contents(h*w, ch) {}

    char get() const {
        return contents[cursor];
    }
    char get(pos r, pos c) const {
        return contents[r*width+c];
    }

    Screen& move(pos r, pos c);
    Screen& set(char ch);
    Screen& set(pos r, pos c, char ch);

    const Screen& display(ostream &os) const {
        os << "const display" << endl;
        do_display(os);
        return *this;
    }
    Screen& display(ostream &os) {
        os << "non-const display" << endl;
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(ostream &os) const {
        for (pos i=0; i<width; ++i) {
            for (pos j=0; j<height; ++j)
                os << contents[i*width+j];
            os << endl;
        }
    }
};


void Window_mgr::clear(ScreenIndex i) {
    if (i>=screens.size())
        return ;
    Screen &s = screens[i];
    s.contents = string(s.height*s.width, ' ');
}

Screen& Screen::move(pos r, pos c) {
    cursor = r*width+c;
    return *this;
}

Screen& Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

Screen& Screen::set(pos r, pos c, char ch) {
    contents[r*width+c] = ch;
    return *this;
}

