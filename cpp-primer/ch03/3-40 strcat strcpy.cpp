#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const char cstr1[] = "hello";
    const char cstr2[] = "world";

    size_t sz = strlen(cstr1) + strlen(" ") + strlen(cstr2);
    char cstr3[sz];
    strcpy(cstr3,cstr1);
    strcat(cstr3," ");
    strcat(cstr3,cstr2);

    cout << cstr3 << endl;

    return 0;
}