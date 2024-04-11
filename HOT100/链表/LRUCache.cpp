#include <unordered_map>
using namespace std;

struct LRUNode
{
    int key, value;
    LRUNode *prev;
    LRUNode *next;
    LRUNode() : key(0), value(0), prev(nullptr), next(nullptr){};
    LRUNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr){};
};

class LRUCache
{
public:
    LRUCache(int capacity) : capacity_(capacity), size_(0)
    {
        head = new LRUNode();
        tail = new LRUNode();
        head->next = tail;
        tail->prev = head;
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
            size_++;
            if (size_ > capacity_)
            {
                LRUNode *removeNode = removeTail();
                LRUMap.erase(removeNode->key);
                delete removeNode;
                size_--;
            }
            return;
        }

        auto keyNode = LRUMap[key];
        keyNode->value = value;
        moveToHead(keyNode);
        return;
    }

    void moveToHead(LRUNode *node)
    {
        removeNode(node);
        addToHead(node);
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
        auto headNxt = head->next;
        head->next = node;
        headNxt->prev = node;
        node->next = headNxt;
        node->prev = head;
    }

    LRUNode *removeTail()
    {
        auto removeNode = tail->prev;
        auto prevNode = tail->prev->prev;
        prevNode->next = tail;
        tail->prev = prevNode;
        return removeNode;
    }

private:
    LRUNode *head;
    LRUNode *tail;
    unordered_map<int, LRUNode *> LRUMap;
    int size_;
    int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */