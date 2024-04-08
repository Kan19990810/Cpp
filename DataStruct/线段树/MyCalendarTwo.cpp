struct Node
{
    Node *left;
    Node *right;
    int val;
    int add;
    Node() : left(nullptr), right(nullptr), val(0), add(0) {}
};

class MyCalendarTwo
{
public:
    MyCalendarTwo()
    {
        root = new Node();
    }

    bool book(int start, int end)
    {
        // cout << query(root, 0, N, start, end - 1) << endl;
        if (query(root, 0, N, start, end - 1) >= 2)
        {
            return false;
        }
        update(root, 0, N, start, end - 1, 1);
        return true;
    }

private:
    Node *root;
    const int N = 1E9 + 7;

    int query(Node *node, int start, int end, int l, int r)
    {
        // 区间不相交
        if (start > r || end < l)
        {
            return 0;
        }
        // 更新区间包含节点区间
        if (l <= start && r >= end)
        {
            return node->val;
        }
        // 区间有相交， 需要查询儿子节点
        int mid = (start + end) >> 1;
        // 将懒惰标识下推
        pushDown(node, mid - start + 1, end - mid);
        int ans;
        // 查询儿子节点
        if (l <= mid)
        {
            ans = query(node->left, start, mid, l, r);
        }
        if (r > mid)
        {
            ans = max(ans, query(node->right, mid + 1, end, l, r));
        }
        return ans;
    }

    void update(Node *node, int start, int end, int l, int r, int val)
    {
        // 区间不相交
        if (start > r || end < l)
        {
            return;
        }
        // 更新区间包含节点区间
        if (l <= start && r >= end)
        {
            node->val += val;
            node->add += val;
            return;
        }
        // 区间有相交， 需要更新儿子节点
        int mid = (start + end) >> 1;
        // 将懒惰标识下推
        pushDown(node, mid - start + 1, end - mid);
        // 更新儿子节点
        if (l <= mid)
        {
            update(node->left, start, mid, l, r, val);
        }
        if (r > mid)
        {
            update(node->right, mid + 1, end, l, r, val);
        }
        // 更新本节点
        pushUp(node);
    }

    void pushDown(Node *node, int leftNum, int rightNum)
    {
        // 懒惰表示下推过程进行动态开点
        if (node->left == nullptr)
        {
            node->left = new Node();
        }
        if (node->right == nullptr)
        {
            node->right = new Node();
        }
        node->left->val += node->add;
        node->right->val += node->add;
        node->left->add += node->add;
        node->right->add += node->add;
        node->add = 0;
    }

    void pushUp(Node *node)
    {
        node->val = max(node->left->val, node->right->val);
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */