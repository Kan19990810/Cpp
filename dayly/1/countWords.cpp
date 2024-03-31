class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<string, int> wordCount;
        for (auto &word : words1)
        {
            wordCount[word]++;
        }
        int ans = 0;
        for (auto &word : words2)
        {
            if (wordCount[word] == 1)
            {
                ans++;
                wordCount[word] = -1;
            }
            else if (wordCount[word] == -1)
            {
                ans--;
                wordCount[word] = -2;
            }
            // cout << ans <<' ' << wordCount[word] << endl;
        }
        return ans;
    }
};