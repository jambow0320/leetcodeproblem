#include <array>
#include <memory>
#include <stdexcept>
#include <string>

using std::array;
using std::invalid_argument;
using std::string;

namespace {
struct TrieNode {
    bool is_word = false;
    array<std::unique_ptr<TrieNode>, 26> children{};
};
}  // namespace

class Trie {
public:
    Trie() : root(std::make_unique<TrieNode>()) {}

    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;
    Trie(Trie&&) = delete;
    Trie& operator=(Trie&&) = delete;

    void insert(const string& word) {
        TrieNode* current = root.get();
        for (char c : word) {
            const size_t index = charIndex(c);
            auto& child = current->children[index];
            if (!child) {
                child = std::make_unique<TrieNode>();
            }
            current = child.get();
        }
        current->is_word = true;
    }

    bool search(const string& word) const {
        const TrieNode* node = findNode(word);
        return node && node->is_word;
    }

    bool startsWith(const string& prefix) const {
        return findNode(prefix) != nullptr;
    }

private:
    std::unique_ptr<TrieNode> root;

    static size_t charIndex(char c) {
        if (c < 'a' || c > 'z') {
            throw invalid_argument("Trie supports lowercase english letters only");
        }
        return static_cast<size_t>(c - 'a');
    }

    const TrieNode* findNode(const string& sequence) const {
        const TrieNode* current = root.get();
        for (char c : sequence) {
            if (c < 'a' || c > 'z') {
                return nullptr;
            }
            const size_t index = static_cast<size_t>(c - 'a');
            const auto& child = current->children[index];
            const TrieNode* next = child.get();
            if (!next) {
                return nullptr;
            }
            current = next;
        }
        return current;
    }
};
