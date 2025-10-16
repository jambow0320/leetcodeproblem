struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        return rever(head, nullptr);
    }

private:
    ListNode* rever(ListNode* u, ListNode* lst)
    {
        ListNode* tmp = u->next;
        u->next = lst;
        if(tmp) return rever(tmp, u);
        else return u;
    }
};