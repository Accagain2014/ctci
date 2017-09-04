
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        // write code here
        ListNode * copy_now = new ListNode(pHead->val);
        ListNode * now = copy_now;

        ListNode * p = pHead->next;
        while(p)
        {
            copy_now->next = new ListNode(p->val);
            copy_now = copy_now->next;
            p = p->next;
        }
        ListNode * reverse_now = reverse(pHead);
        while(now && reverse_now)
        {
            if(now->val != reverse_now->val)
                return false;
            now = now->next;
            reverse_now = reverse_now->next;
        }
        if(now || reverse_now)
            return false;
        return true;

    }
    ListNode * reverse(ListNode * pHead)
    {
        ListNode * pre = pHead;
        ListNode * now = pHead->next;

        pre->next = NULL;
        while(now)
        {
            ListNode * temp = now->next;
            now->next = pre;
            pre = now;
            now = temp;
        }
        return pre;
    }
};