#include <unordered_map>
#include <iostream>
using namespace std;

struct LRUNode
{
    int key, value;
    LRUNode *prev;
    LRUNode *next;
    LRUNode() : key(0), value(0), prev(nullptr), next(nullptr){};
    LRUNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr){};
};

class LRU
{
private:
    LRUNode *head;
    LRUNode *tail;
    unordered_map<int, LRUNode *> LRUMap;
    int size;
    int capacity;

public:
    LRU(int cap) : capacity(cap), size(0)
    {
        head = new LRUNode();
        tail = new LRUNode();
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(LRUNode *node)
    {
        auto preNode = node->prev;
        auto nxtNode = node->next;
        preNode->next = nxtNode;
        nxtNode->prev = preNode;
    }

    void addToHead(LRUNode *node)
    {
        LRUNode *headNxt = head->next;
        head->next = node;
        headNxt->prev = node;
        node->next = headNxt;
        node->prev = head;
    }

    void moveToHead(LRUNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    LRUNode *removeTail()
    {
        auto removeNode = tail->prev;
        auto prevNode = tail->prev->prev;
        prevNode->next = tail;
        tail->prev = prevNode;
        return removeNode;
    }

    int get(int key)
    {
        if (LRUMap.count(key) == 0)
        {
            return -1;
        }

        auto targetNode = LRUMap[key];
        moveToHead(targetNode);
        return targetNode->value;
    }

    void put(int key, int value)
    {
        if (LRUMap.count(key) == 0)
        {
            auto keyNode = new LRUNode(key, value);
            LRUMap[key] = keyNode;
            addToHead(keyNode);
            size++;
            if (size > capacity)
            {
                LRUNode *removeNode = removeTail();
                LRUMap.erase(removeNode->key);
                delete removeNode;
                size--;
            }
            return;
        }

        auto keyNode = LRUMap[key];
        keyNode->value = value;
        moveToHead(keyNode);
        return;
    }

    void show()
    {
        for (auto it = head->next; it != tail; it = it->next)
        {
            cout << it->value << endl;
        }
    }
};

int main()
{

    LRU lru(3);

    lru.put(1, 1);
    lru.put(2, 2);
    lru.put(3, 3);
    lru.get(1);
    lru.put(4, 4);
    lru.show();
    return 0;
}