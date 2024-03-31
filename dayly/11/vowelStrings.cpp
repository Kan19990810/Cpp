#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int vowelStrings(vector<string> &words, int left, int right)
    {
        unordered_set<char> alpha = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            string word = words[i];
            int size_word = word.size();
            if (alpha.count(word[0]) != 0 && alpha.count(word[size_word - 1]) != 0)
            {
                ans++;
            }
        }
        return ans;
    }
};