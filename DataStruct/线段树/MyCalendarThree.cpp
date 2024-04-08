struct Node
{
    Node *left;
    Node *right;
    int val;
    int add;
    Node() : left(nullptr), right(nullptr), val(0), add(0){};
};

class MyCalendarThree
{
public:
    MyCalendarThree()
    {
        root = new Node();
    }

    int book(int startTime, int endTime)
    {
        update(root, 0, N, startTime, endTime - 1, 1);
        return query(root, 0, N, 0, N);
    }

private:
    Node *root;
    const int N = 1E9 + 7;
    void update(Node *node, int start, int end, int l, int r, int val)
    {
        if (start > r || end < l)
        {
            return;
        }
        if (l <= start && end <= r)
        {
            node->val += val;
            node->add += val;
            return;
        }
        int mid = (start + end) >> 1;
        pushDown(node, mid - start + 1, end - mid);
        if (l <= mid)
        {
            update(node->left, start, mid, l, r, val);
        }
        if (r >= mid)
        {
            update(node->right, mid + 1, end, l, r, val);
        }
        pushUp(node);
    }

    void pushDown(Node *node, int leftNum, int rightNum)
    {
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
        return;
    }

    int query(Node *node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return node->val;
        }
        int mid = (start + end) >> 1;
        pushDown(node, mid - start + 1, end - mid);
        int ans;
        if (l <= mid)
        {
            ans = query(node->left, start, mid, l, r);
        }
        if (mid <= r)
        {
            ans = max(ans, query(node->right, mid + 1, end, l, r));
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */