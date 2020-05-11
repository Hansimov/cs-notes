int f(int,int);

using pf1 = decltype(f) *;
vector<pf1> v1;

typedef decltype(f) *pf2;
vector<pf2> v2;

using pf3 = int(*)(int,int);
vector<pf3> v3;

using pf4 = int (int, int);
vector<pf4*> v4;

typedef int(*pf5)(int,int);
vector<pf5> v5;

using pf6 = decltype(f);
vector<pf6*> v6;