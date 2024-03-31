class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> alpha_num(26, 0);
        for (auto &maga : magazine)
        {
            alpha_num[maga - 'a']++;
        }
        for (auto &ransom : ransomNote)
        {
            alpha_num[ransom - 'a']--;
            if (alpha_num[ransom - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};