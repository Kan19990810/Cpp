struct Node
{
    Node *left;
    Node *right;
    int val, add;
    Node() : left(nullptr), right(nullptr), val(0), add(0){};
};
class MyCalendar
{
public:
    MyCalendar()
    {
        root = new Node();
    }

    bool book(int start, int end)
    {
        // cout << query(root, 0, N, start, end - 1) << endl;
        if (query(root, 0, N, start, end - 1) > 0)
        {
            return false;
        }
        update(root, 0, N, start, end - 1, 1);
        return true;
    }

private:
    static const int N = 1e9 + 7;
    Node *root;

    // 节点范围[start, end]  更新范围[l, r]
    void update(Node *node, int start, int end, int l, int r, int val)
    {
        // 范围没有交接
        if (l > end || r < start)
        {
            return;
        }
        // 节点范围在更新范围内
        if (l <= start && r >= end)
        {
            node->val += (end - start + 1) * val;
            node->add += val;
            return;
        }

        // 范围有交接但不包含，更新子节点
        int mid = (start + end) >> 1;
        // 将懒惰标记下推
        pushDown(node, mid - start + 1, end - mid);
        if (l <= mid)
        {
            update(node->left, start, mid, l, r, val);
        }
        if (r > mid)
        {
            update(node->right, mid + 1, end, l, r, val);
        }
        // 使用子节点更新值来更新节点值
        pushUp(node);
    }

    void pushDown(Node *node, int leftNum, int RightNum)
    {
        // 懒惰标记+动态开点实现动态线段树
        if (node->left == nullptr)
        {
            node->left = new Node();
        }
        if (node->right == nullptr)
        {
            node->right = new Node();
        }
        if (node->add == 0)
        {
            return;
        }
        node->left->val += leftNum * node->add;
        node->right->val += RightNum * node->add;
        node->left->add += node->add;
        node->right->add += node->add;
        node->add = 0;
    }

    void pushUp(Node *node)
    {
        node->val = node->left->val + node->right->val;
    }

    int query(Node *node, int start, int end, int l, int r)
    {
        // 查询和更新的逻辑差不多
        // 如果区间没有交集
        if (start > r || end < l)
        {
            return 0;
        }
        // 查询区间包括了节点区间
        if (l <= start && r >= end)
        {
            return node->val;
        }
        // 区间有交集，查询子节点
        // 查询之前需要懒惰标记下推
        int mid = (start + end) >> 1;
        int ans = 0;
        pushDown(node, mid - start + 1, end - mid);
        if (l <= mid)
        {
            ans += query(node->left, start, mid, l, r);
        }
        if (r > mid)
        {
            ans += query(node->right, mid + 1, end, l, r);
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */