struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyhead = new ListNode();
        ListNode *ptr = dummyhead;

        int carrybit = 0;
        while(1)
        {
            int now = carrybit;
            carrybit = 0;
            if(l1) now += l1->val;
            if(l2) now += l2->val;

            if(now >= 10) 
            {
                carrybit += now / 10;
                now %= 10;
            }

            if(l1) ptr->next = l1;
            else if(l2) ptr->next = l2;
            else
            {
                if(now != 0 || carrybit != 0)
                {
                    ptr->next = new ListNode();
                }
                else break;
            }

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            ptr = ptr->next;
            ptr->val = now;
        }

        ListNode *ans = dummyhead->next;
        delete dummyhead;
        return ans;
    }
};