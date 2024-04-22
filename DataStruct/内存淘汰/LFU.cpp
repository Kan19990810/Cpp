#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

struct Node
{
    int key, value, frequence;
    Node(int k, int v, int f) : key(k), value(v), frequence(f){};
};

/**
 * freq_table[f] 每次都执行erase和push_front
 *
 * key_table 每次都需更改 k 对应的迭代器
 *
 * minF 更新时 +1， 新节点时变为 1
 */

class LFU
{
private:
    int minF, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;

public:
    LFU(int cap) : minF(0), capacity(cap){};

    int get(int k)
    {
        if (key_table.find(k) == key_table.end())
        {
            return -1;
        }
        auto node = key_table[k];
        int v = node->value;
        int f = node->frequence;

        freq_table[f].erase(node); // 迭代器失效

        if (freq_table[f].size() == 0 && minF == f)
            minF++;

        freq_table[f + 1].push_front(Node(k, v, f + 1));
        key_table[k] = freq_table[f + 1].begin();
        return v;
    }

    void put(int k, int v)
    {
        if (key_table.find(k) != key_table.end())
        {
            auto node = key_table[k];
            int f = node->frequence;
            freq_table[f].erase(node);

            if (freq_table[f].size() == 0 && minF == f)
                minF++;

            freq_table[f + 1].push_front(Node(k, v, f + 1));
            key_table[k] = freq_table[f + 1].begin();
            return;
        }

        if (key_table.size() == capacity)
        {
            auto it = freq_table[minF].back();
            key_table.erase(it.key);
            freq_table[minF].pop_back();
        }

        freq_table[1].push_front(Node(k, v, 1));
        key_table[k] = freq_table[1].begin();
        minF = 1;
        return;
    }
};