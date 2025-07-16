class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                while(slow!=head){
                    slow=slow->next;
                    head=head->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};