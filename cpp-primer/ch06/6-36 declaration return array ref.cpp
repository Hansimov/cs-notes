string (& func(string (&arr_str)[10]))[10];

using ArrStr = string[10];
ArrStr func(ArrStr & arr_str);

auto func(ArrStr& arr_str) -> string(&)[10];

string arr_s[10];
decltype(arr_s) & func(ArrStr & arr_str);