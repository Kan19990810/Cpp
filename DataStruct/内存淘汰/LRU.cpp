#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    Node *prev;
    Node *next;
    int key;
    int value;
    Node() : prev(nullptr), next(nullptr), key(0), value(0){};
    Node(int k, int v) : prev(nullptr), next(nullptr), key(k), value(v){};
};

class LRU
{
private:
    Node *head;
    Node *tail;
    int capacity;
    int size;
    unordered_map<int, Node *> map;

public:
    LRU(int cap) : capacity(cap), size(0)
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int x)
    {
        if (map.count(x) == 0)
        {
            return -1;
        }

        auto node = map[x];
        moveToHead(node);
        return node->value;
    }

    void push(int k, int v)
    {
        if (map.count(k) != 0)
        {
            auto node = map[k];
            moveToHead(node);
            node->value = v;
            return;
        }

        if (size >= capacity)
        {
            auto removeNode = remove();
            moveNode(removeNode);
            map.erase(removeNode->key);
            size--;
        }
        auto newNode = new Node(k, v);
        addToHead(newNode);
        map[k] = newNode;
        size++;
    }

    Node *remove()
    {
        return tail->prev;
    }

    void moveToHead(Node *node)
    {
        moveNode(node);
        addToHead(node);
    }

    void moveNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node *node)
    {
        auto tmp = head->next;
        node->next = tmp;
        tmp->prev = node;
        head->next = node;
        node->prev = head;
    }
};

int main()
{
    LRU lru(2);

    for (int i = 1; i < 4; ++i)
    {
        lru.push(i, i);
    }

    for (int i = 1; i < 4; ++i)
    {
        cout << lru.get(i) << ' ';
    }
}
