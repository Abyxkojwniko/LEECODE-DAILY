class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr;
        ListNode *p=head;
        while(p){
            ListNode *next=p->next;
            p->next=pre;
            pre=p;
            p=next;
        }
        return pre;
    }
};