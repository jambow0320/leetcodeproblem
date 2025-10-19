// 实现 LRU (最近最少使用) 缓存 约束的数据结构，形式为key-value形式
// 用一个双向链表，离头越远的意味着越久未被使用的key，为防止边界问题，加入一个dummyhead和dummytail
// 然后用一个哈希map维护key到指针的映射

#include <unordered_map>

using std::unordered_map;

struct DLinkNode
{
    int key, value;
    DLinkNode *prev, *next;
    DLinkNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {};
};

class LRUCache {
private:
    int _cap;
    DLinkNode *dummyhead, *dummytail;
    unordered_map<int, DLinkNode*> cache;

    void addToHead(DLinkNode *node)
    {
        DLinkNode *tmp = dummyhead->next;
        dummyhead->next = node;
        node->prev = dummyhead;
        node->next = tmp;
        tmp->prev = node;
    }

    void removeNode(DLinkNode *node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

public:
    LRUCache(int capacity) : _cap(capacity) {
        dummyhead = new DLinkNode(0, 0);
        dummytail = new DLinkNode(0, 0);
        dummyhead->next = dummytail;
    }

    ~LRUCache() 
    {
        for(auto kvpair : cache)
            delete kvpair.second;
        delete dummyhead;
        delete dummytail;
        cache.clear();
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        
        DLinkNode *node = cache[key];
        removeNode(node);
        addToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.count(key))
        {
            DLinkNode *node = cache[key];
            node->value = value;
            removeNode(node);
            addToHead(node);
        }
        else
        {
            if(!_cap) 
            {
                DLinkNode *tmp = dummytail->prev;
                removeNode(tmp);
                cache.erase(tmp->key);
                delete tmp;
                ++_cap;
            }
            DLinkNode *node = new DLinkNode(key, value);
            addToHead(node);
            cache[key] = node;
            --_cap;
        }
    }
};