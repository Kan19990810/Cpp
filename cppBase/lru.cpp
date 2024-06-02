#include <unordered_map>
#include <iostream>
using namespace std;

struct LruNode
{
    int key;
    int value;
    LruNode *pre;
    LruNode *nxt;
    LruNode() : key(0), value(0), pre(nullptr), nxt(nullptr) {}
    LruNode(int k, int v) : key(k), value(v), pre(nullptr), nxt(nullptr) {}
};

class Lru
{
private:
    LruNode *head;
    LruNode *tail;
    int size;
    int capacity;
    unordered_map<int, LruNode *> keyMap;

    void removenode(LruNode *node)
    {
        node->nxt->pre = node->pre;
        node->pre->nxt = node->nxt;
    }
    void addtohead(LruNode *node)
    {
        auto nxtnode = head->nxt;
        head->nxt = node;
        node->pre = head;
        nxtnode->pre = node;
        node->nxt = nxtnode;
    }
    void movetohead(LruNode *node)
    {
        removenode(node);
        addtohead(node);
    }

    LruNode *removetail()
    {
        auto node = tail->pre;
        removenode(node);
        return node;
    }

public:
    Lru(int c) : capacity(c), size(0)
    {
        head = new LruNode();
        tail = new LruNode();
        head->nxt = tail;
        tail->pre = head;
    }

    int get(int k)
    {
        if (keyMap.count(k) == 0)
        {
            return -1;
        }
        auto node = keyMap[k];
        movetohead(node);
        return node->value;
    }

    void put(int k, int v)
    {
        if (keyMap.count(k) == 0)
        {
            if (size >= capacity)
            {
                auto node = removetail();
                keyMap.erase(node->key);
                size--;
            }
            auto node = new LruNode(k, v);
            keyMap[k] = node;
            addtohead(node);
            size++;
        }
        else
        {
            auto node = keyMap[k];
            node->value = v;
            movetohead(node);
        }
    }
};

int main()
{
    Lru lru(3);
    lru.put(1, 1);
    cout << lru.get(1) << endl;
    lru.put(2, 2);
    lru.put(3, 3);
    lru.put(4, 4);
    cout << lru.get(1) << endl;
    return 0;
}