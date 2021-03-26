#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <list>
#include <utility>  // pair

using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int,int>> dlist;
    unordered_map<int, list<pair<int,int>>::iterator> map; 

public:
    LRUCache(int capacity) : cap(capacity) {
    }

    void disp() {
        for (auto const x : map) {
            cout << x.first << " " << (*x.second).second << ", ";
        }
        cout << endl;
    }
    
    int get(int key) {
        if (map.count(key) == 0)
            return -1;
        dlist.push_front(*map[key]);
        dlist.erase(map[key]);
        map[key] = dlist.begin();
        return dlist.front().second;
        // disp();
    }
    
    void put(int key, int value) {
        if (map.count(key) == 0) {
            if (map.size() == cap) {
                map.erase(dlist.back().first);
                dlist.pop_back();
            }
            dlist.push_front(make_pair(key, value));
            map[key] = dlist.begin();
        } else {
            dlist.erase(map[key]);
            dlist.push_front(make_pair(key, value));
            map[key] = dlist.begin();
        }
        // disp();
    }
};

int main() {
    // LRUCache lRUCache = new LRUCache(2);
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {2=2, 1=1}
    lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {3=3, 1=1}
    lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.get(1);    // 返回 -1 (未找到)
    lRUCache.get(3);    // 返回 3
    lRUCache.get(4);    // 返回 4

    return 0;
}