class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *pre=dummy;
        while(pre->next&&pre->next->next){
            ListNode *temp1=pre->next->next;
            ListNode *temp2=pre->next;
            ListNode *lat=temp1->next;
            pre->next=temp1;
            temp1->next=temp2;
            temp2->next=lat;
            pre=temp2;
        }
        return dummy->next;
    }
};