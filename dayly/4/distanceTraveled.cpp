class Solution
{
public:
    int distanceTraveled(int mainTank, int additionalTank)
    {
        int dis = 0;
        while (mainTank)
        {
            for (int i = 1; i <= 5; i++)
            {
                if (mainTank)
                {
                    mainTank--;
                    dis++;
                }
                else
                {
                    return dis * 10;
                }
            }

            if (additionalTank)
            {
                mainTank++;
                additionalTank--;
            }
        }
        return dis * 10;
    }
};