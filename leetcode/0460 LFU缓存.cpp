/*

* LFU缓存 - LFU缓存 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/lfu-cache/solution/lfuhuan-cun-by-leetcode-solution/

*/

struct Node {
    int key, val, freq;
    Node(int key, int val, int freq)
        : key(key), val(val), freq(freq) {}
};

class LFUCache {
    int min_freq, cap;
    unordered_map<int, list<Node>> freq_map;
    unordered_map<int, list<Node>::iterator> key_map;
public:
    LFUCache(int capacity) {
        min_freq = 0;
        cap = capacity;
        freq_map.clear();
        key_map.clear();
    }
    
    int get(int key) {
        if (cap==0)
            return -1;
        auto itr = key_map.find(key);
        if (itr == key_map.end())
            return -1;
        auto node_itr = itr->second;
        int val = node_itr->val, freq = node_itr->freq;
        freq_map[freq].erase(node_itr);
        if (freq_map[freq].size()==0) {
            freq_map.erase(freq);
            if (freq == min_freq)
                min_freq += 1;
        }
        freq_map[freq+1].push_front(Node(key,val,freq+1));
        key_map[key] = freq_map[freq+1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if (cap==0)
            return ;
        auto itr = key_map.find(key);
        if (itr == key_map.end()) {
            if (key_map.size() == cap) {
                auto to_erase_node = freq_map[min_freq].back();
                key_map.erase(to_erase_node.key);
                freq_map[min_freq].pop_back();
                if (freq_map[min_freq].size()==0) {
                    freq_map.erase(min_freq);
                }
            }
            freq_map[1].push_front(Node(key,value,1));
            key_map[key] = freq_map[1].begin();
            min_freq = 1;
        } else {
            auto node_itr = itr->second;
            int freq = node_itr->freq;
            freq_map[freq].erase(node_itr);
            if (freq_map[freq].size()==0) {
                freq_map.erase(freq);
                if (min_freq==freq)
                    min_freq += 1;
            }
            freq_map[freq+1].push_front(Node(key,value,freq+1));
            key_map[key] = freq_map[freq+1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */