struct TrieNode
{
    bool isEnd;
    vector<TrieNode *> chil;
    TrieNode() : chil(26), isEnd(false) {}
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        auto node = root;
        for (auto ch : word)
        {
            if (node->chil[ch - 'a'] == nullptr)
            {
                node->chil[ch - 'a'] = new TrieNode();
            }
            node = node->chil[ch - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        auto node = root;
        for (auto ch : word)
        {
            if (node->chil[ch - 'a'] == nullptr)
            {
                return false;
            }
            node = node->chil[ch - 'a'];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        auto node = root;
        for (auto ch : prefix)
        {
            if (node->chil[ch - 'a'] == nullptr)
            {
                return false;
            }
            node = node->chil[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */