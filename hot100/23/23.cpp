#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using std::vector;
using std::pair;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    struct comp
    {
        bool operator() (const pair<int, ListNode*> &a, const pair<int, ListNode*> &b)
        {
            return a.first > b.first;
        }
    };

    int getsize(ListNode *u)
    {
        int sz = 0;
        while(u)
        {
            ++sz;
            u = u->next;
        }
        return sz;
    }

    pair<int, ListNode*> mergelist(pair<int, ListNode*> a, pair<int, ListNode*> b)
    {
        int sz = a.first + b.first;
        ListNode *u = a.second, *v = b.second;
        ListNode *dummyhead = new ListNode;
        ListNode *now = dummyhead;

        while(u && v)
        {
            if(u->val > v->val) std::swap(u, v);
            now->next = u;
            u = u->next;
            now = now->next;
        }
        if(v) std::swap(u, v);
        while(u)
        {
            now->next = u;
            u = u->next;
            now = now->next;
        }

        now = dummyhead->next;
        delete dummyhead;

        return std::make_pair(sz, now);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return nullptr;

        std::priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, comp> q;
        
        for(auto x : lists)
        {
            int sz = getsize(x);
            q.push(std::make_pair(sz, x));
        }

        while(q.size() > 1)
        {
            pair<int, ListNode*> top1 = q.top();
            q.pop();
            pair<int, ListNode*> top2 = q.top();
            q.pop();

            pair<int, ListNode*> u = mergelist(top1, top2);
            q.push(u);
        }

        return q.top().second;
    }
};