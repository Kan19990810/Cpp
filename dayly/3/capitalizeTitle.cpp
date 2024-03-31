class Solution
{
public:
    string capitalizeTitle(string title)
    {
        int n = title.size();
        int l = 0, r = 0;
        title.push_back(' ');
        while (r < n)
        {
            while (title[r] != ' ')
            {
                ++r;
            }
            if (r - l > 2)
            {
                title[l] = toupper(title[l]);
                ++l;
            }
            while (l < r)
            {
                title[l] = tolower(title[l]);
                ++l;
            }
            l = r + 1;
            ++r;
        }
        title.pop_back();
        return title;
    }
};