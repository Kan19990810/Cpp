class Solution
{
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {
        // (tomato - 2 * cheese) / 2 = jumbo
        // cheese - jumbo = small
        int jumbo, small;
        if (tomatoSlices - 2 * cheeseSlices < 0)
        {
            return {};
        }

        if ((tomatoSlices - 2 * cheeseSlices) % 2 == 0)
        {
            jumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
        }
        else
        {
            return {};
        }

        if (cheeseSlices - jumbo < 0)
        {
            return {};
        }
        small = cheeseSlices - jumbo;
        return {jumbo, small};
    }
};