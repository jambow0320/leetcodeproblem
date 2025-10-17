struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if(!head) return head;

        int len = 0;
        ListNode* u = head;
        while(!u)
        {
            ++len;
            u = u->next;
        }

        for(int i = 0; (1 << i) < len; ++i)
        {
            ;
        }
    }
};