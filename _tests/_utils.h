#include <cstdio>
#include <iostream>
#include <vector>
#include <iterator> // begin, end
#include <cstdarg>  // va_list, va_start, va_end, va_arg

template <typename T>
void disp(const std::vector<T> & v) {
    for (auto const &ele: v)
        std::cout << ele << " ";
    std::cout << std::endl;
}

// Python-like print in c++
//  https://gist.github.com/ilebedie/f006674098a1adaab731
// variadic functions - Variable number of arguments in C++? - Stack Overflow
//  https://stackoverflow.com/questions/1657883/variable-number-of-arguments-in-c
// 省略号和可变参数模板 | Microsoft Docs
//  https://docs.microsoft.com/zh-cn/cpp/cpp/ellipses-and-variadic-templates
// Parameter pack(since C++11) - cppreference.com
//  https://en.cppreference.com/w/cpp/language/parameter_pack
// 可变参数模板 - 维基百科，自由的百科全书
//  https://zh.wikipedia.org/wiki/可变参数模板
// va_start和va_end使用详解 - Healtheon - 博客园
//  https://www.cnblogs.com/hanyonglu/archive/2011/05/07/2039916.html

void disp() {
    std::cout << std::endl;
}

template <typename T, typename ... REST>
void disp(const T & t, const REST & ... rest) {
    std::cout << t << " ";
    disp(rest...);
}