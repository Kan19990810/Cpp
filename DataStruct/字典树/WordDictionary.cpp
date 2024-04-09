struct TrieNode
{
    vector<TrieNode *> children;
    bool isEnd;

    TrieNode() : children(26), isEnd(false){};
};

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        auto node = root;
        for (auto ch : word)
        {
            int tmp = ch - 'a';
            if (node->children[tmp] == nullptr)
            {
                node->children[tmp] = new TrieNode();
            }
            node = node->children[tmp];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        return dfs(word, 0, root);
    }

private:
    TrieNode *root;

    bool dfs(string word, int index, TrieNode *node)
    {
        if (index == word.size())
        {
            return node->isEnd;
        }

        char ch = word[index];
        if (ch >= 'a' && ch <= 'z')
        {
            TrieNode *child = node->children[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child))
            {
                return true;
            }
        }
        else if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                TrieNode *child = node->children[i];
                if (child != nullptr && dfs(word, index + 1, child))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */