class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *pre=dummy;
        ListNode *lat=dummy;
        for(int i=0;i<n;i++){
            if(!lat->next) return head;
            lat=lat->next;
        }
        while(lat->next){
            lat=lat->next;
            pre=pre->next;
        }
        pre->next=pre->next->next;
        return dummy->next;
    }
};