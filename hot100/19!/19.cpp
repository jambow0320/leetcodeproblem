/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点，要求一遍扫描完成
用双指针就行
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    void forward(ListNode *&u, int step)
    {
        while(step--) u = u->next;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode *fast = dummyhead, *slow = dummyhead;
        forward(fast, n);
        
        while(1)
        {
            forward(fast, 1);
            if(fast == nullptr)
            {
                ListNode *tmp = slow->next;
                slow->next= tmp->next;
                delete tmp;
                return dummyhead->next;
            }
            forward(slow, 1);
        }
    }
};