class Solution
{
public:
    long long minimumPerimeter(long long neededApples)
    {
        // l = 2 , (2, 1, 2 * 4 -  2 , 2, 2 , 2)
        // l = 4 , (4, 3 ,2, 3, 4 * 4 - 4, 4, 4, 4)
        // l = n , (n , ..., n / 2 *4 - n * 4)
        long long l = 0, num = 0;
        while (num < neededApples)
        {
            l += 2;
            num += 3 * l * l;
        }
        return 4 * l;
    }
};