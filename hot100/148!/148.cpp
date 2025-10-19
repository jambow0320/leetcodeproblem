// 翻转链表，因为链表的性质，所以不适合使用swap的快排，只能用归并
// 但是归并要递归实现的话，额外空间是log级别（栈空间）
// 所以只能选择从底层合并上来的归并排序方法，这样额外空间是O(1)级别

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
        ListNode *curr = head;
        while(curr)
        {
            ++len;
            curr = curr->next;
        }

        ListNode dummyHead = ListNode(0, head);
        for(int sublen = 1; sublen < len; sublen <<= 1)
        {
            ListNode *prev = &dummyHead; 
            ListNode *curr = dummyHead.next;

            while(curr)
            {
                ListNode *head1 = curr;
                ListNode *head2 = split(head1, sublen);
                curr = split(head2, sublen);
                prev = merge(head1, head2, prev);
            }
        }

        return dummyHead.next;
    }

private:
    ListNode *split(ListNode *head, int len)
    {
        while(head && --len)
        {
            head = head->next;
        }
        if(!head) return nullptr;
        ListNode *nexthead = head->next;
        head->next = nullptr;
        return nexthead;
    }

    ListNode *merge(ListNode *head1, ListNode *head2, ListNode *prev)
    {
        ListNode *curr = prev;

        while(head1 && head2)
        {
            if(head1->val <= head2->val)
            {
                curr->next = head1;
                head1 = head1->next;
            }
            else
            {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        curr->next = head1 ? head1 : head2;
        while(curr->next) curr = curr->next;

        return curr;
    }
};