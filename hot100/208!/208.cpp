#include <string>
#include <array>
#include <memory>

using std::array;
using std::string;
using std::unique_ptr;

struct Trienode
{
    bool is_word = false;
    array<unique_ptr<Trienode>, 26> children{};
};

class Trie
{
public:
    Trie() : root(std::make_unique<Trienode>()) {}

    void insert(string word)
    {
        Trienode *u = root.get();
        for (auto c : word)
        {
            const size_t index = c - 'a';
            auto &child = u->children[index];
            if (!child)
                child = std::make_unique<Trienode>();
            u = child.get();
        }
        u->is_word = true;
    }

    bool search(string word)
    {
        Trienode *u = root.get();
        for (auto c : word)
        {
            const size_t index = c - 'a';
            auto &child = u->children[index];
            if (!child)
                return false;
            u = child.get();
        }
        return u->is_word;
    }

    bool startsWith(string prefix)
    {
        Trienode *u = root.get();
        for (auto c : prefix)
        {
            const size_t index = c - 'a';
            auto &child = u->children[index];
            if (!child)
                return false;
            u = child.get();
        }
        return true;
    }

private:
    unique_ptr<Trienode> root;
};

int main() {}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */