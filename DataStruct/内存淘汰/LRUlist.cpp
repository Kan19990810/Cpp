#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

struct Node
{
    int key;
    int value;
    Node() : key(0), value(0){};
    Node(int k, int v) : key(k), value(v){};
};

class LRUCache
{
private:
    int cap;
    list<Node> lruL;
    unordered_map<int, list<Node>::iterator> map;

    /**
     * list 每次都执行erase和push_front
     *
     * map 每次都需更改 k 对应的迭代器
     *
     */

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key)
    {
        if (map.find(key) == map.end())
        {
            return -1;
        }
        auto it = map[key];
        int v = it->value;
        lruL.erase(it);
        lruL.push_front(Node(key, v));
        map[key] = lruL.begin();
        return v;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            auto it = map[key];
            lruL.erase(it);
            lruL.push_front(Node(key, value));
            map[key] = lruL.begin();
            return;
        }

        if (lruL.size() >= cap)
        {
            auto it = lruL.back();
            map.erase(it.key);
            lruL.pop_back();
        }

        lruL.push_front(Node(key, value));
        map[key] = lruL.begin();
    }
};

// int main()
// {
//     LRUCache lru(2);

//     lru.push(2, 1);
//     lru.push(2, 2);
//     cout << lru.get(2) << endl;
//     lru.push(1, 1);
//     lru.push(4, 1);
//     cout << lru.get(2) << endl;
//     return 0;
// }
