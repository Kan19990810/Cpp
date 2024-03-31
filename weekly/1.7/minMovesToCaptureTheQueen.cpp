class Solution
{
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
    {
        // 象直接到达
        // 同一对角线
        if (c - d == e - f)
        {
            // 车不在同一对角线
            if (a - b != c - d)
            {
                return 1;
            }
            // 车在同一对角线，但是不在范围内
            if (a - b == c - d && c < e && (a < c || a > e))
            {
                return 1;
            }
            if (a - b == c - d && e < c && (a < e || a > c))
            {
                return 1;
            }
        }

        if (c + d == e + f)
        {
            // 车不在同一对角线
            if (a + b != c + d)
            {
                return 1;
            }
            // 车在同一对角线，但是不在范围内
            if (a + b == c + d && c < e && (a < c || a > e))
            {
                return 1;
            }
            if (a + b == c + d && e < c && (a < e || a > c))
            {
                return 1;
            }
        }

        // 车直接到达
        // 同一直线内
        if (a == e)
        {
            // 象不在直线内
            if (c != a)
            {
                return 1;
            }
            // 象在直线内但不在范围
            if (c == a && b < f && (d < b || d > f))
            {
                return 1;
            }
            if (c == a && b > f && (d > b || d < f))
            {
                return 1;
            }
        }

        if (b == f)
        {
            // 象不在直线内
            if (d != b)
            {
                return 1;
            }
            // 象在直线内但不在范围
            if (d == b && a < e && (c < a || c > e))
            {
                return 1;
            }
            if (d == b && a > e && (c > a || c < e))
            {
                return 1;
            }
        }

        // 车象不能直接到达， 车两步到达
        return 2;

        // 有没有需要三步的情形
    }
};