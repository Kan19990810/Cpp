struct TrieNode
{
    vector<TrieNode *> children;
    bool isEnd;
    TrieNode() : children(26), isEnd(false){};
};
class Trie
{
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
        auto node = root;
        for (auto ch : word)
        {
            int tmp = ch - 'a';
            if (node->children[tmp] == nullptr)
            {
                return false;
            }
            node = node->children[tmp];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        auto node = root;
        for (auto ch : prefix)
        {
            int tmp = ch - 'a';
            if (node->children[tmp] == nullptr)
            {
                return false;
            }
            node = node->children[tmp];
        }
        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */